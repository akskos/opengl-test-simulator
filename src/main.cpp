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

using namespace std;

const GLfloat color_data[] = {
    0.0f, 0.5f, 1.0f,
    0.0f, 0.5f, 0.2f,
    0.0f, 0.5f, 1.0f
};

float xcoord = -1.0;
float xdelta = 0.1;

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

    glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10.0f);
    glm::mat4 view = glm::lookAt(
	glm::vec3(0, 0, 1),
	glm::vec3(0, 0, 0),
	glm::vec3(0, 1, 0)
    );
    glm::mat4 model = glm::mat4(1.0);
    glm::mat4 mvp = projection * view * model;

    GLuint matrixId = glGetUniformLocation(programId, "mvp");

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(programId);

	double time = glfwGetTime();
	double interval = time - lastTime;

	// change xcoord
	xcoord += xdelta * interval;
	if (xcoord > 0.5 || xcoord < -1.0) {
	    xdelta = -xdelta;
	}

	// Send MVP to glsl
	glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);

	const GLfloat vertex_data[] = {
	    xcoord, -1.0f, 0.0f,
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

	glfwSwapBuffers(window);
	glfwPollEvents();

	lastTime = glfwGetTime();
    }

    glfwTerminate();
    return 0;
}
