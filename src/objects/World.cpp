#include "World.h"

using namespace std;
namespace ob = object_builder;

World::World() {}

void World::render(Graphics graphics) {
  for (vector<Renderable*>::iterator it = objects.begin(); it != objects.end(); it++) {
    Renderable* r = *it;
    r->render(graphics);
  }
}

void World::addObject(Renderable* object) {
  objects.push_back(object); 
}

void World::addObjects(vector<Renderable*> objects) {
  this->objects.insert(this->objects.begin(), objects.begin(), objects.end());
}

void World::update(double interval) {

}