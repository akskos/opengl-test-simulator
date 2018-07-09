#ifndef _ACTOR_H
#define _ACTOR_H

#include "../Graphics.h"
#include "../Util.h"

class Actor {
public:
    virtual void setMovingDirection(Util::Direction direction) = 0;
};

#endif