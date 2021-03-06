#include "MoveCommand.h"

typedef Util::Direction Direction;

MoveCommand::MoveCommand(Direction direction):
direction(direction)
{}

void MoveCommand::execute(Actor& actor) {
    if (down) {
        actor.startMovingTo(direction);
    } else {
        actor.stopMovingTo(direction);
    }
}

void MoveCommand::setDown(bool down) {
    this->down = down;
}