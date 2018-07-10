#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "commands/Command.h"
#include "commands/MoveCommand.h"
#include "commands/RotateCommand.h"

class InputController {
public:
    InputController();
    std::vector<Command*> pollCommands();

private:    
    KeyboardCommand* w;
    KeyboardCommand* a;
    KeyboardCommand* s;
    KeyboardCommand* d;
    MouseCommand* mouseMove;
    MouseCommand* leftMouseClick;
};
