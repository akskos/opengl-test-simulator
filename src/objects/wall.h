#ifndef _WALL_H
#define _WALL_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "rect.h"
#include "../Graphics.h"

class Wall {
public:
  Wall(glm::vec3 position, glm::vec3 wallVector, float thickness);
  void render(Graphics graphics);
  void update(double interval);
  void setColor(glm::vec3 color);

private:
  std::vector<Rect*> rects;
  double thickness;
};

#endif
