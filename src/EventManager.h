#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <functional>

class EventManager {
public:
    bool addEvent(std::string name, std::function<void()> action);
    void executeEvent(std::string name);

private:
    std::map<std::string, std::function<void()>> actions;
};

#endif