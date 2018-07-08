#include "./Event.h"

Event::Event() {}

Event::Event(EventType type):
type(type)
{

}

EventType Event::getType() {
    return type;
}