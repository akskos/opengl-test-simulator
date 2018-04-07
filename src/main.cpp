#include <GL/glew.h>
//#include <GL3/gl3.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <boost/program_options.hpp>

#include "program.h"
#include "shader.h"
#include "input.h"
#include "camera.h"
#include "objects/rect.h"
#include "objects/floor.h"
#include "objects/wall.h"
#include "objects/World.h"
#include "objects/ObjectBuilder.h"
#include "EventManager.h"
#include "options.h"
#include "config.h"

#define PROGRAM_NAME "Test Simulator"

using namespace std;
namespace ob = object_builder;

InputController input;
Camera camera;
EventManager em;

const GLfloat speed = 4.0f;

const GLfloat color_data[] = {
    0.0f, 0.5f, 1.0f,
    0.0f, 0.5f, 0.2f,
    0.0f, 0.5f, 1.0f
};

void quit() {
    SDL_Quit();
    exit(0);
}

void pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEMOTION) {
            double hdelta = event.motion.xrel / 200.0;
            double vdelta = event.motion.yrel / 200.0;
            camera.instaHorizRotate(hdelta);
            camera.instaVertiRotate(vdelta);
        }
        input.keyboardCallback(event);
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            em.executeEvent("test");
        }
    }
}

int main(const int argc, const char** argv) {
    Config::initWithDefaults();
    options::parseOptions(argc, argv);

    SDL_Window* window = NULL;
    SDL_GLContext context;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(
	    PROGRAM_NAME,
	    SDL_WINDOWPOS_CENTERED,
	    SDL_WINDOWPOS_CENTERED,
	    Config::getWindowSize(),
	    Config::getWindowSize(),
	    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    context = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    input.addBinding(SDLK_ESCAPE, SDL_KEYUP, [=]() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(0);
    });
    input.addBinding(SDLK_UNKNOWN, SDL_QUIT, [=]() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(0);
    });
    input.addBinding(SDLK_d, SDL_KEYDOWN, []() {
	camera.move(glm::vec3(speed, 0.0f, 0.0f));
    });
    input.addBinding(SDLK_d, SDL_KEYUP, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));	    
    });
    input.addBinding(SDLK_a, SDL_KEYDOWN, []() {
	camera.move(glm::vec3(-speed, 0.0f, 0.0f));	    
    });
    input.addBinding(SDLK_a, SDL_KEYUP, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));	    
    });
    input.addBinding(SDLK_w, SDL_KEYDOWN, []() {
	camera.move(glm::vec3(0.0f, 0.0f, speed));
    });
    input.addBinding(SDLK_w, SDL_KEYUP, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));
    });
    input.addBinding(SDLK_s, SDL_KEYDOWN, []() {
	camera.move(glm::vec3(0.0f, 0.0f, -speed));
    });
    input.addBinding(SDLK_s, SDL_KEYUP, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));
    });
    input.addBinding(SDLK_LEFT, SDL_KEYDOWN, []() {
	camera.rotate(-0.03f);
    });
    input.addBinding(SDLK_RIGHT, SDL_KEYDOWN, []() {
	camera.rotate(0.03f);
    });
    input.addBinding(SDLK_LEFT, SDL_KEYUP, []() {
	camera.rotate(0);
    });
    input.addBinding(SDLK_RIGHT, SDL_KEYUP, []() {
	camera.rotate(0);
    });

    em.addEvent("test", []() {
        cout << "test event" << endl;
    });

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 3;
    }

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);

    GLuint cbo;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_data), color_data, GL_STATIC_DRAW);

    Shader vertexShader(GL_VERTEX_SHADER, "src/vertex.shader");
    Shader fragmentShader(GL_FRAGMENT_SHADER, "src/fragment.shader");
    Program program(vertexShader.getShaderId(), fragmentShader.getShaderId());
    GLuint programId = program.getProgramId();

    GLuint matrixId = glGetUniformLocation(programId, "mvp");

    Rect rect(
	glm::vec3(-1.0f, -1.0f, -1.0f),	    
	glm::vec3(1.0f, -1.0f, -1.0f),	    
	glm::vec3(1.0f, 1.0f, -1.0f),	    
	glm::vec3(-1.0f, 1.0f, -1.0f)	    
    );

    Floor floor;
    Renderable* world = ob::buildWorld();

    Wall wall(glm::vec3(-15, -2, 15), glm::vec3(10, 0, 7), 1.0f);
    wall.setColor(glm::vec3(0.1f, 0.9f, 0.7f));

    Wall wall2(glm::vec3(-5, -2, -5), glm::vec3(5, 0, 5), 7.07f);
    wall2.setColor(glm::vec3(1.0f, 0.3f, 0.4f));

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    unsigned lastTicks = SDL_GetTicks();
    while (true) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(programId);

	unsigned ticks = SDL_GetTicks();
	double interval = (ticks - lastTicks) / 1000.0;
	lastTicks = SDL_GetTicks();

	camera.update(interval);
	glm::mat4 mvp = camera.getMVP();
	glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);

	const GLfloat vertex_data[] = {
	    -1.0f, -1.0f, 0.0f,
	     1.0f, -1.0f, 0.0f,
	     0.0f,  1.0f, 0.0f
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	rect.render();
	floor.render();
	wall.render();
	wall2.render();
  world->render();

	SDL_GL_SwapWindow(window);
	
	pollEvents();
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
