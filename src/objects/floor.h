#ifndef _FLOOR_H
#define _FLOOR_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>

#include "rect.h"
#include "Renderable.h"

class Floor : public Renderable {
public:
    Floor();
    void render();

private:
    std::vector<Rect *> rects;
};

#endif
