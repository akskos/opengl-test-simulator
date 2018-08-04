#include "Graphics.h"

using namespace std;

Graphics::Graphics() {}

bool Graphics::init() {
    if (!initGlew()) {
        cout << "Failed to init glew" << endl;
        return false;
    }
    if (!loadShaders()) {
        cout << "Failed to load shaders" << endl;
        return false;
    }
    initVAO();
    return true;
}

bool Graphics::initGlew() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return false;
    }
    return true;
}

bool Graphics::loadShaders() {
    Shader vertexShader(GL_VERTEX_SHADER, "src/vertex.shader");
    Shader fragmentShader(GL_FRAGMENT_SHADER, "src/fragment.shader");
    Program program(vertexShader.getShaderId(), fragmentShader.getShaderId());
    GLuint programId = program.getProgramId();
    matrixId = glGetUniformLocation(programId, "mvp");
    glUseProgram(programId);
    return true;
}

void Graphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::updateMVP(glm::mat4 mvp) {
    glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void Graphics::initVAO() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}
