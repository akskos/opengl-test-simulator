#ifndef _OBJECT_BUILDER_H
#define _OBJECT_BUILDER_H

#include <vector>

#include "rect.h"
#include "World.h"
#include "floor.h"

class World;

namespace object_builder {
  World* buildWorld();
  std::vector<Rect*> buildTunnel();
}

#endif
