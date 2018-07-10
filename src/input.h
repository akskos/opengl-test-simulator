#include <SDL2/SDL.h>
#include <stdlib.h>
#include <functional>
#include <map>
#include <vector>
#include <iostream>

#include "commands/Command.h"
#include "commands/MoveCommand.h"
#include "commands/RotateCommand.h"

class InputController {
public:
    InputController();

    void keyboardCallback(SDL_Event event);
    void addBinding(SDL_Keycode, unsigned int action, std::function<void()> callback);

    std::vector<Command*> pollCommands();

private:
    std::map<SDL_Keycode, std::map<int, std::function<void()>>> callbacks;
    
    KeyboardCommand* arrowUp;
    KeyboardCommand* arrowDown;
    KeyboardCommand* arrowLeft;
    KeyboardCommand* arrowRight;
    MouseCommand* mouseMove;
    MouseCommand* leftMouseClick;
};
