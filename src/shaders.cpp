#include "shaders.h"
#include "shader.h"

using namespace std;

GLuint shaders_load(string vertexShaderPath, string fragmentShaderPath) {
    Shader vertexShader(GL_VERTEX_SHADER, vertexShaderPath);
    Shader fragmentShader(GL_FRAGMENT_SHADER, fragmentShaderPath);
    GLuint vertexShaderId = vertexShader.getShaderId();
    GLuint fragmentShaderId = fragmentShader.getShaderId();
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShaderId);
    glAttachShader(program, fragmentShaderId);
    glLinkProgram(program);
    GLint result;
    int infoLogLength;
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
	GLchar *log = (GLchar *)malloc(infoLogLength+1);	
	glGetProgramInfoLog(program, infoLogLength, NULL, log);
	printf("%s\n", log);
	free(log);
    }
    glDetachShader(program, vertexShaderId);
    glDetachShader(program, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    return program;
}
