#ifndef _KEYBOARD_COMMAND_H
#define _KEYBOARD_COMMAND_H

#include "Command.h"

class KeyboardCommand: public Command {
public:
    virtual void setDown(bool down) = 0;
};

#endif