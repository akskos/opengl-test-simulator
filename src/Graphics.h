#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>

#include "shader.h"
#include "program.h"

class Graphics {
public:
    Graphics();
    bool init();
    void clear();
    void updateMVP(glm::mat4 mvp);

private:
    bool initGlew();
    bool loadShaders();
    void initVAO();

    GLuint vao;
    GLuint matrixId;
};

#endif
