#include "camera.h"

Camera::Camera() {
    projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10.0f);
    view = glm::lookAt(
	glm::vec3(0, 0, 1),
	glm::vec3(0, 0, 0),
	glm::vec3(0, 1, 0)
    );
    model = glm::mat4(1.0f);
}

glm::mat4 Camera::getMVP() {
    return projection * view * model;
}
