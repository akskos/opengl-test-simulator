#include "input.h"

using namespace std;
typedef Util::Direction Direction;

InputController::InputController() {
    arrowUp = nullptr;
    arrowDown = nullptr;
    arrowLeft = new MoveCommand(Direction::LEFT);
    arrowDown = nullptr;
    mouseMove = new RotateCommand();
    leftMouseClick = nullptr;
}

vector<Command*> InputController::pollCommands() {
    vector<Command*> commands;
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(nullptr);
    Uint8 left = keyState[SDL_SCANCODE_A];
    Uint8 right = keyState[SDL_SCANCODE_D];
    Uint8 up = keyState[SDL_SCANCODE_W];
    Uint8 down = keyState[SDL_SCANCODE_S];
    if (left && up) {
        commands.push_back(new MoveCommand(Direction::LEFT_DIAGONAL_FORWARD));
    } else if (left && down) {
        commands.push_back(new MoveCommand(Direction::LEFT_DIAGONAL_BACKWARD));
    } else if (left) {
        commands.push_back(new MoveCommand(Direction::LEFT));
    } else if (right && up) {
        commands.push_back(new MoveCommand(Direction::RIGHT_DIAGONAL_FORWARD));
    } else if (right && down) {
        commands.push_back(new MoveCommand(Direction::RIGHT_DIAGONAL_BACKWARD));
    } else if (right) {
        commands.push_back(new MoveCommand(Direction::RIGHT));
    } else if (up) {
        commands.push_back(new MoveCommand(Direction::FORWARD));
    } else if (down) {
        commands.push_back(new MoveCommand(Direction::BACK));
    } else {
        commands.push_back(new MoveCommand(Direction::STOP));
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEMOTION) {
            mouseMove->setCoordinates(
                event.motion.xrel,
                event.motion.yrel
            );
            commands.push_back(mouseMove); 
        } else if (event.type == SDL_QUIT) {
            // Quit
        }
    }

    return commands;
}