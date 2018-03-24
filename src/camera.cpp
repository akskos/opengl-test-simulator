#include "camera.h"

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, 1.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getMVP() {
    glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 50.0f);
    glm::mat4 view = glm::lookAt(
	position,
	position + front,
	up
    );
    glm::mat4 model = glm::mat4(1.0f);
    return projection * view * model;
}

void Camera::move(glm::vec3 delta) {
    positionDelta = delta;
}

void Camera::rotate(double delta) {
    frontDelta = -delta;
}

void Camera::update(double interval) {
    glm::vec3 deltaVec1;
    if (positionDelta.z != 0) {
	deltaVec1 = front * (float)interval * positionDelta.z;
    }
    glm::vec3 deltaVec2;
    if (positionDelta.x != 0) {
	deltaVec2 = glm::normalize(glm::cross(front, up)) * (float)interval * positionDelta.x;
    }
    position += deltaVec1 + deltaVec2;

    glm::mat4 rotationMat = glm::rotate(glm::mat4(1), (float)frontDelta, glm::vec3(0, 1, 0));
    front = glm::vec3(rotationMat * glm::vec4(front, 1.0f));
}
