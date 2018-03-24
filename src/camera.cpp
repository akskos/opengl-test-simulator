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
    //eyesOnDelta = delta;
}

void Camera::rotate(double rad) {
    //eyesOn.x += sin(rad);
    //eyesOn.z += cos(rad);
}

void Camera::update(double interval) {
    const glm::vec3 deltaVec1 = front * (float)interval * positionDelta;
    const glm::vec3 deltaVec2 = glm::normalize(glm::cross(front, up)) * (float)interval * positionDelta;
    position += deltaVec1 + deltaVec2;
    //eyesOn += eyesOnDelta * (float)interval;
}
