#ifndef _MOUSE_COMMAND_H
#define _MOUSE_COMMAND_H

#include "Command.h"

class MouseCommand: public Command {
public:
    virtual void setCoordinates(int x, int y) = 0;
};

#endif