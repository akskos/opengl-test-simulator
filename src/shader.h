#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

class Shader {
public:
    Shader(GLenum shaderType);
    Shader(GLenum shaderType, std::string filePath);
    void load(std::string filePath);
    void destroy();
    GLuint getShaderId();

private:
    GLenum shaderType;
    GLuint shaderId;

    std::string fileToString(std::string filePath);
    void compile(std::string source);
    void check();
};
