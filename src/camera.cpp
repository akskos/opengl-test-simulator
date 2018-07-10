#include "camera.h"

using namespace std;
typedef Util::Direction Direction;

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, 10.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getMVP() {
    const float fov = Config::getFov();
    glm::mat4 projection = glm::perspective(glm::radians(fov), aspect_ratio, near_clip, far_clip);
    glm::mat4 view = glm::lookAt(
      position,
      position + front,
      up
    );
    glm::mat4 model = glm::mat4(1.0f);
    return projection * view * model;
}

void Camera::setXMoveVector(glm::vec3 vec) {
  xMoveVector = vec; 
}

void Camera::setZMoveVector(glm::vec3 vec) {
  zMoveVector = vec;
}
/*
void Camera::rotate(double delta) {
    frontDelta = -delta;
}*/

void Camera::vrotate(double delta) {
    vrotateDelta = -delta;    
}

void Camera::rotate(int x, int y) {
  double xdelta = x / 200.0;
  glm::mat4 rotationMat = glm::rotate(glm::mat4(1), (float)-xdelta, up);
  front = glm::vec3(rotationMat * glm::vec4(front, 1.0f));

  double ydelta = y / 200.0;
  glm::vec3 rotationAxis = glm::cross(front, up);
  rotationMat = glm::rotate(glm::mat4(1), (float)-ydelta, rotationAxis);
  glm::vec3 newFront = glm::vec3(rotationMat * glm::vec4(front, 1.0f));
  if (newFront.y > -0.99 && newFront.y < 0.99) {
    front = newFront;
  }
}

void Camera::instaHorizRotate(double delta) {
    glm::mat4 rotationMat = glm::rotate(glm::mat4(1), (float)-delta, up);
    front = glm::vec3(rotationMat * glm::vec4(front, 1.0f));
}

void Camera::instaVertiRotate(double delta) {
    glm::vec3 rotationAxis = glm::cross(front, up);
    glm::mat4 rotationMat = glm::rotate(glm::mat4(1), (float)-delta, rotationAxis);
    glm::vec3 newFront = glm::vec3(rotationMat * glm::vec4(front, 1.0f));
    if (newFront.y > -0.99 && newFront.y < 0.99) {
      front = newFront;
    }
}

void Camera::move(glm::vec3 vec, double interval) {
  glm::vec3 deltaVec1;
  glm::vec3 movingFront = glm::normalize(glm::vec3(front.x, 0, front.z));
  if (vec.z != 0) {
    deltaVec1 = movingFront * (float)interval * vec.z;
  }
  glm::vec3 deltaVec2;
  if (vec.x != 0) {
    deltaVec2 = glm::normalize(glm::cross(front, up)) * (float)interval * vec.x;
  }
  position += deltaVec1 + deltaVec2;
}

void Camera::update(double interval) {
  move(xMoveVector, interval);
  move(zMoveVector, interval);

  glm::mat4 rotationMat = glm::rotate(glm::mat4(1), (float)frontDelta, glm::vec3(0, 1, 0));
  front = glm::vec3(rotationMat * glm::vec4(front, 1.0f));

  glm::vec3 rotationAxis = glm::cross(front, up);
  glm::mat4 vRotationMat = glm::rotate(glm::mat4(1), (float)vrotateDelta, rotationAxis);
  front = glm::vec3(vRotationMat * glm::vec4(front, 1.0));
}

void Camera::setMovingDirection(Direction direction) {
  switch (direction) {
  case Direction::LEFT:
    setXMoveVector(glm::vec3(-4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 0));
    break;
  case Direction::RIGHT:
    setXMoveVector(glm::vec3(4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 0));
    break;
  case Direction::FORWARD:
    setXMoveVector(glm::vec3(0, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 4));
    break;
  case Direction::BACK:
    setXMoveVector(glm::vec3(0, 0, 0));
    setZMoveVector(glm::vec3(0, 0, -4));
    break;
  case Direction::STOP:
    setXMoveVector(glm::vec3(0, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 0));
    break;
  case Direction::LEFT_DIAGONAL_FORWARD:
    setXMoveVector(glm::vec3(-4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 4));
    break;
  case Direction::LEFT_DIAGONAL_BACKWARD:
    setXMoveVector(glm::vec3(-4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, -4));
    break;
  case Direction::RIGHT_DIAGONAL_FORWARD:
    setXMoveVector(glm::vec3(4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, 4));
    break;
  case Direction::RIGHT_DIAGONAL_BACKWARD:
    setXMoveVector(glm::vec3(4, 0, 0));
    setZMoveVector(glm::vec3(0, 0, -4));
    break;
  default:
    break;
  }
}

void Camera::render(Graphics graphics) {
  graphics.updateMVP(getMVP());
}