#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "KeyboardCommand.h"
#include "../actors/Actor.h"
#include "../Util.h"

class MoveCommand: public KeyboardCommand {
public:
    MoveCommand(Util::Direction direction);
    void execute(Actor& actor);
    void setDown(bool down);

private:
    bool down;
    Util::Direction direction;
};

#endif