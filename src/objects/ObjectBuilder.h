#ifndef _OBJECT_BUILDER_H
#define _OBJECT_BUILDER_H

#include <vector>

#include "rect.h"

namespace object_builder {
  using namespace std;

  vector<Rect*> buildTunnel() {
    vector<Rect*> rects;
    rects.push_back(new Rect(
      glm::vec3(9, -2, 18),
      glm::vec3(18, -2, 18),
      glm::vec3(18, -2, 30),
      glm::vec3(9, -2, 30)
    ));
    rects[0]->setColor(glm::vec3(1.0f, 0.4f, 0.7f));
    rects.push_back(new Rect(
      glm::vec3(9, -2, 18),
      glm::vec3(9, 5, 18),
      glm::vec3(9, 5, 30),
      glm::vec3(9, -2, 30)
    ));
    rects[1]->setColor(glm::vec3(0.4f, 1.0f, 0.7f));
    rects.push_back(new Rect(
      glm::vec3(18, -2, 18),
      glm::vec3(18, 5, 18),
      glm::vec3(18, 5, 30),
      glm::vec3(18, -2, 30)
    ));
    rects[2]->setColor(glm::vec3(0.7f, 0.3f, 1.0f));
    rects.push_back(new Rect(
      glm::vec3(9, 5, 18),
      glm::vec3(18, 5, 18),
      glm::vec3(18, 5, 30),
      glm::vec3(9, 5, 30)
    ));
    rects[3]->setColor(glm::vec3(0.2f, 0.4f, 0.7f));

    return rects;
  }
}

#endif