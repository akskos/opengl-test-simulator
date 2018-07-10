#include "MoveCommand.h"

typedef Util::Direction Direction;

MoveCommand::MoveCommand(Direction direction):
direction(direction)
{}

void MoveCommand::execute(Actor& actor) {
    actor.setMovingDirection(direction);
}

void MoveCommand::setDown(bool down) {
    this->down = down;
}