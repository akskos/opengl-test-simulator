#include "program.h"

using namespace std;

Program::Program(GLuint vertexShaderId, GLuint fragmentShaderId) {
    this->programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId); 
    glAttachShader(programId, fragmentShaderId); 
    glLinkProgram(programId);
    check();
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
}

void Program::check() {
    GLint result;
    int infoLogLength;
    glGetProgramiv(programId, GL_LINK_STATUS, &result);
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
	GLchar *log = new GLchar[infoLogLength+1]();	
	glGetProgramInfoLog(programId, infoLogLength, NULL, log);
	cerr << log << endl;
	delete[] log;
    }
}

GLuint Program::getProgramId() {
    return programId;
}
