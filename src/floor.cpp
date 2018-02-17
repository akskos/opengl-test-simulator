#include "floor.h"

Floor::Floor() {
    GLfloat size = 0.5f;
    for (int i = 0; i < 50; i++) {
	GLfloat x_offset = (GLfloat)i * size;
	for (int j = 0; j < 50; j++) {
	    if (j % 2 == i % 2) {
		continue;
	    }
	    GLfloat z_offset = (GLfloat)j * size;
	    rects.push_back(new Rect(
		glm::vec3(-10.0f + x_offset, -2.0f, -10.0f + z_offset),
		glm::vec3(-10.0f + x_offset, -2.0f, -10.0f + size + z_offset),
		glm::vec3(-10.0f + size + x_offset, -2.0f, -10.0f + size + z_offset),
		glm::vec3(-10.0f + size + x_offset, -2.0f, -10.0f + z_offset)
	    ));
	}
    }
}

void Floor::render() {
    for (Rect *r : rects) {
	r->render();
    }
}
