#include "shaders.h"

GLuint shaders_load(const char *vertexShaderSource, const char *fragmentShaderSource) {
    GLint result;
    int infoLogLength;
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShaderId, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderId);
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
	GLchar *log = (GLchar *)malloc(infoLogLength+1);	
	glGetShaderInfoLog(vertexShaderId, infoLogLength, NULL, log);
	printf("%s\n", log);
	free(log);
    }
    glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderId);
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
	GLchar *log = (GLchar *)malloc(infoLogLength+1);	
	glGetShaderInfoLog(fragmentShaderId, infoLogLength, NULL, log);
	printf("%s\n", log);
	free(log);
    }
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShaderId);
    glAttachShader(program, fragmentShaderId);
    glLinkProgram(program);
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
