#include "World.h"

using namespace std;
namespace ob = object_builder;

World::World() {
  vector<Rect*> tunnel_rects = ob::buildTunnel(); 
  objects.insert(objects.begin(), tunnel_rects.begin(), tunnel_rects.end());
}

void World::render() {
  for (vector<Renderable*>::iterator it = objects.begin(); it != objects.end(); it++) {
    Renderable* r = *it;
    r->render();
  }
}
