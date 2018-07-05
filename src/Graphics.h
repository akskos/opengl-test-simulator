#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class Graphics {
public:
    Graphics();
    bool init();
    void clear();

private:
    bool initGlew();
};

#endif