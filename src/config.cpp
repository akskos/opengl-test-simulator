#include "config.h"

int Config::window_size;
float Config::fov;

void Config::initWithDefaults() {
  window_size = 512;
  fov = 90.0;
}

void Config::setWindowSize(int size) {
  window_size = size;
}

int Config::getWindowSize() {
  return window_size;
}

void Config::setFov(float fov) {
  Config::fov = fov;
}

float Config::getFov() {
  return fov;
}
