#ifndef _OBJECT_BUILDER_H
#define _OBJECT_BUILDER_H

#include <vector>

#include "rect.h"
#include "World.h"

namespace object_builder {
  Renderable* buildWorld();
  std::vector<Rect*> buildTunnel();
}

#endif
