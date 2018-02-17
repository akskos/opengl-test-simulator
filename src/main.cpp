#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "program.h"
#include "shader.h"
#include "input.h"
#include "camera.h"
#include "rect.h"
#include "floor.h"

using namespace std;

InputController input;
Camera camera;

const GLfloat speed = 2.0f;

const GLfloat color_data[] = {
    0.0f, 0.5f, 1.0f,
    0.0f, 0.5f, 0.2f,
    0.0f, 0.5f, 1.0f
};

void quit() {
    glfwTerminate();
    exit(0);
}

void keyboardCallbackWrapper(GLFWwindow *window, int key, int scancode, int action, int mods) {
    input.keyboardCallback(window, key, scancode, action, mods); 
}

int main() {
    GLFWwindow *window;
    if (!glfwInit()) {
	return 1;
    }

    window = glfwCreateWindow(500, 500, "Hello", NULL, NULL);
    if (!window) {
	glfwTerminate();
	return 2;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(2);
    glfwSetKeyCallback(window, keyboardCallbackWrapper);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    input.addBinding(GLFW_KEY_D, GLFW_PRESS, []() {
	camera.move(glm::vec3(speed, 0.0f, 0.0f));
    });
    input.addBinding(GLFW_KEY_D, GLFW_RELEASE, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));	    
    });
    input.addBinding(GLFW_KEY_A, GLFW_PRESS, []() {
	camera.move(glm::vec3(-speed, 0.0f, 0.0f));	    
    });
    input.addBinding(GLFW_KEY_A, GLFW_RELEASE, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));	    
    });
    input.addBinding(GLFW_KEY_W, GLFW_PRESS, []() {
	camera.move(glm::vec3(0.0f, 0.0f, -speed));
    });
    input.addBinding(GLFW_KEY_W, GLFW_RELEASE, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));
    });
    input.addBinding(GLFW_KEY_S, GLFW_PRESS, []() {
	camera.move(glm::vec3(0.0f, 0.0f, speed));
    });
    input.addBinding(GLFW_KEY_S, GLFW_RELEASE, []() {
	camera.move(glm::vec3(0.0f, 0.0f, 0.0f));
    });
    input.addBinding(GLFW_KEY_ESCAPE, GLFW_PRESS, quit);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
	glfwTerminate();
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

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(programId);

	double time = glfwGetTime();
	double interval = time - lastTime;

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

	glfwSwapBuffers(window);
	glfwPollEvents();

	lastTime = glfwGetTime();
    }

    glfwTerminate();
    return 0;
}
