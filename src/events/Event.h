#ifndef _EVENT_H
#define _EVENT_H

enum EventType {
    MOVE_FORWARD,
    MOVE_BACK,
    MOVE_LEFT,
    MOVE_RIGHT
};

class Event {
public:
    Event();
    Event(EventType type);

    EventType getType();

private:
    EventType type;
};

#endif