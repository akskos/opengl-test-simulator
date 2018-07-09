#include "input.h"

using namespace std;
typedef Util::Direction Direction;

InputController::InputController() {
    arrowUp = nullptr;
    arrowDown = nullptr;
    arrowLeft = new MoveCommand(Direction::LEFT);
    arrowDown = nullptr;
}

void InputController::keyboardCallback(SDL_Event event) {
    SDL_Keycode key = event.key.keysym.sym;
    if (callbacks.find(key) == callbacks.end()) {
	return;
    }
    if (callbacks[key].find(event.type) == callbacks[key].end()) {
	return;
    }
    callbacks[key][event.type]();
}

void InputController::addBinding(SDL_Keycode key, unsigned int action, std::function<void()> callback) {
    callbacks[key][action] = callback;
}

vector<Command*> InputController::pollCommands() {
    vector<Command*> commands;
    cout << "getting keyboard state" << endl;
    SDL_PumpEvents();
    int numkeys;
    const Uint8* keyState = SDL_GetKeyboardState(&numkeys);
    cout << "got " << numkeys << " key states" << endl;
    cout << "got keyboard state" << endl;
    Uint8 left = keyState[SDL_SCANCODE_A];
    cout << "left assigned" << endl;
    Uint8 right = keyState[SDL_SCANCODE_D];
    Uint8 up = keyState[SDL_SCANCODE_W];
    Uint8 down = keyState[SDL_SCANCODE_S];
    cout << "assigned boolean variables" << endl;
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
    cout << "created new commands" << endl;
    return commands;
}