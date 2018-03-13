#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

class Program {
public:
    Program(GLuint vertexShaderId, GLuint fragmentShaderId);
    GLuint getProgramId();

private:
    GLuint programId;

    void check();
    void detach();
};
