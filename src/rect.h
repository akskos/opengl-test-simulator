#ifndef _RECT_H
#define _RECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Rect {
public:
    Rect(
	glm::vec3 point1,
	glm::vec3 poin2,
	glm::vec3 point3,
	glm::vec3 point4
    );
    void render();

private:
    GLuint vbo;
    GLuint cbo;
};

#endif
