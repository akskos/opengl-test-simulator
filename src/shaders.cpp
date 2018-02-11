#include "shaders.h"
#include "shader.h"
#include "program.h"

using namespace std;

GLuint shaders_load(string vertexShaderPath, string fragmentShaderPath) {
    Shader vertexShader(GL_VERTEX_SHADER, vertexShaderPath);
    Shader fragmentShader(GL_FRAGMENT_SHADER, fragmentShaderPath);
    GLuint vertexShaderId = vertexShader.getShaderId();
    GLuint fragmentShaderId = fragmentShader.getShaderId();
    Program program(vertexShader.getShaderId(), fragmentShader.getShaderId());
    vertexShader.destroy();
    fragmentShader.destroy();

    return program.getProgramId();
}
