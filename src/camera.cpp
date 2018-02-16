#include "camera.h"

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, -1.0f);
    eyesOn = glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::mat4 Camera::getMVP() {
    glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10.0f);
    glm::mat4 view = glm::lookAt(
	position,
	eyesOn,
	glm::vec3(0, 1, 0)
    );
    glm::mat4 model = glm::mat4(1.0f);
    return projection * view * model;
}

void Camera::move(glm::vec3 delta) {
    positionDelta = delta;
    eyesOnDelta = delta;
}

void Camera::update(double interval) {
    position += positionDelta * (float)interval;
    eyesOn += eyesOnDelta * (float)interval;
}
