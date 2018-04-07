#ifndef _CONFIG_H
#define _CONFIG_H

class Config {
public:
  static void initWithDefaults();
  static void setWindowSize(int size);
  static int getWindowSize();

private:
  static int window_size;
};

#endif
