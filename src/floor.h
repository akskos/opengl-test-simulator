#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>

#include "rect.h"

class Floor {
public:
    Floor();
    void render();

private:
    std::vector<Rect *> rects;
};
