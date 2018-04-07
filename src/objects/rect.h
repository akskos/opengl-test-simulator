#ifndef _RECT_H
#define _RECT_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "Renderable.h"

class Rect: public Renderable {
public:
  Rect();
  Rect(
    glm::vec3 point1,
    glm::vec3 poin2,
    glm::vec3 point3,
    glm::vec3 point4
  );
  Rect(
    glm::vec3 point1,
    glm::vec3 poin2,
    glm::vec3 point3,
    glm::vec3 point4,
    glm::vec3 color
  );
  void setColor(glm::vec3 color);
  void render();

private:
  void init(
    glm::vec3 point1,
    glm::vec3 poin2,
    glm::vec3 point3,
    glm::vec3 point4
  );
  GLuint vbo;
  GLuint cbo;
};

#endif
