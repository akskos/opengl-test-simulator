#ifndef _COMMAND_H
#define _COMMAND_H

#include "../actors/Actor.h"

class Command {
public:
    virtual void execute(Actor& actor) = 0;
};

#endif