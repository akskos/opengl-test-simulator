#ifndef _WORLD_H
#define _WORLD_H

#include <vector>

#include "Renderable.h"
#include "ObjectBuilder.h"

class World {
  public:
    World();
    void render();

  private:
    std::vector<Renderable*> objects; 
};

#endif
