#ifndef _ACTOR_H
#define _ACTOR_H

#include "../Graphics.h"
#include "../events/Event.h"

class Actor {
public:
    virtual void update(double interval) = 0;
    virtual void render(Graphics graphics) = 0;
    virtual void handleEvent(Event event) = 0;
};

#endif