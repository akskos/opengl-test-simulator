#ifndef _WORLD_H
#define _WORLD_H

#include <vector>

#include "Renderable.h"
#include "ObjectBuilder.h"

class World: public Renderable {
  public:
    World();
    void render();
    void addObject(Renderable* object);
    void addObjects(std::vector<Renderable*> objects);

  private:
    std::vector<Renderable*> objects; 
};

#endif
