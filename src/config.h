#ifndef _CONFIG_H
#define _CONFIG_H

class Config {
public:
  static void initWithDefaults();
  static void setWindowSize(int size);
  static int getWindowSize();
  static void setFov(float fov);
  static float getFov();

private:
  static int window_size;
  static float fov;
};

#endif
