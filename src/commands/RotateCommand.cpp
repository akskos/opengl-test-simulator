#include "RotateCommand.h"

void RotateCommand::execute(Actor& actor) {
    actor.rotate(x, y);
}

void RotateCommand::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}