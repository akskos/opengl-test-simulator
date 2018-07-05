#include "Graphics.h"

Graphics::Graphics() {}

bool Graphics::init() {
    return initGlew();
}

bool Graphics::initGlew() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return false;
    }
}

void Graphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}