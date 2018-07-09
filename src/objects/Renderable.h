#ifndef _RENDERABLE_H
#define _RENDERABLE_H

#include "../Graphics.h"

class Renderable {
  public:
    virtual void update(double interval) = 0;
    virtual void render(Graphics graphics) = 0;
};

#endif
