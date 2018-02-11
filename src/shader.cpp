#include "shader.h"

using namespace std;

Shader::Shader(GLenum shaderType) {
    this->shaderType = shaderType;
}

Shader::Shader(GLenum shaderType, string filePath) {
    this->shaderType = shaderType;
    load(filePath);
}

void Shader::compile(string source) {
    const char *sourcePtr = source.c_str();
    glShaderSource(shaderId, 1, &sourcePtr, NULL);
    glCompileShader(shaderId);
}

void Shader::load(string filePath) {
    shaderId = glCreateShader(shaderType);
    string source = fileToString(filePath);
    compile(source);
    check();
}

void Shader::check() {
    GLint result;
    int infoLogLength;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
	GLchar *log = new GLchar[infoLogLength+1]();
	glGetShaderInfoLog(shaderId, infoLogLength, NULL, log);
	cerr << log << endl;
	delete[] log;
    }
}

string Shader::fileToString(string filePath) {
    ifstream file(filePath.c_str());    
    string str(
	    (istreambuf_iterator<char>(file)),
	    istreambuf_iterator<char>()
    );
    return str;
}

GLuint Shader::getShaderId() {
    return shaderId;
}
