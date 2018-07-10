#ifndef _ROTATE_COMMAND_H
#define _ROTATE_COMMAND_H

#include "MouseCommand.h"
#include "../actors/Actor.h"

class RotateCommand: public MouseCommand {
public:
    void execute(Actor& actor);
    void setCoordinates(int x, int y);

private:
    int x;
    int y;
};

#endif