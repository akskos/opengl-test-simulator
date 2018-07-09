#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "Command.h"
#include "../actors/Actor.h"
#include "../Util.h"

class MoveCommand: public Command {
public:
    MoveCommand(Util::Direction direction);
    void execute(Actor& actor);

private:
    Util::Direction direction;
};

#endif