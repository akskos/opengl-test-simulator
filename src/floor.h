#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "rect.h"

class Floor {
public:
    Floor();
    void render();

private:
    std::vector<Rect *> rects;
};
