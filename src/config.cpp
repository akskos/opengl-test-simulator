#include "config.h"

int Config::window_size;

void Config::initWithDefaults() {
  window_size = 512;
}

void Config::setWindowSize(int size) {
  window_size = size;
}

int Config::getWindowSize() {
  return window_size;
}
