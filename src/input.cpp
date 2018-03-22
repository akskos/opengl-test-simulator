#include "input.h"

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
