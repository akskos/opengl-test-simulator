#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "shaders.h"

const char *vertexShaderSource =
    "#version 320 es\n" \
    "layout(location = 0) in vec3 vertexPosition_modelspace;\n" \
    "layout(location = 1) in vec3 vertexColor;\n" \
    "out vec3 fragmentColor;\n" \
    "void main() {\n" \
    "  gl_Position.xyz = vertexPosition_modelspace;\n" \
    "  gl_Position.w = 1.0;\n" \
    "  fragmentColor = vertexColor;\n" \
    "}\n";

const char *fragmentShaderSource =
    "#version 320 es\n" \
    "precision mediump float;\n" \
    "in vec3 fragmentColor;\n" \
    "out vec3 color;\n" \
    "void main() {\n" \
    "  color = fragmentColor;\n" \
    "}\n";

const GLfloat vertex_data[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f
};

const GLfloat color_data[] = {
    0.0f, 0.5f, 1.0f,
    0.0f, 0.5f, 0.2f,
    0.0f, 0.5f, 1.0f
};

int main() {
    GLFWwindow *window;
    if (!glfwInit()) {
	return 1;
    }

    window = glfwCreateWindow(640, 480, "Hello", NULL, NULL);
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
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    GLuint cbo;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_data), color_data, GL_STATIC_DRAW);

    GLuint program = shaders_load("src/vertex.shader", "src/fragment.shader");

    while (!glfwWindowShouldClose(window)) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(program);

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
    }

    glfwTerminate();
    return 0;
}
