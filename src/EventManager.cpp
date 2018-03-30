#include "EventManager.h"

using namespace std;

bool EventManager::addEvent(string name, function<void()> action) {
    actions[name] = action;
    return true;
}

void EventManager::executeEvent(string name) {
    actions[name]();
}