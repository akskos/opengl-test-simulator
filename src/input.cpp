/*
#include "input.h"

void InputController::keyboardCallback(
	GLFWwindow *window,
	int key,
	int scancode,
	int action,
	int mods) {
    if (callbacks.find(key) == callbacks.end()) {
	return;
    }
    if (callbacks[key].find(action) == callbacks[key].end()) {
	return;
    }
    callbacks[key][action]();
}

void InputController::addBinding(int key, int action, std::function<void()> callback) {
    callbacks[key][action] = callback;
}
*/
