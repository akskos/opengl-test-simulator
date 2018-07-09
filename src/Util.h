#ifndef _UTIL_H
#define _UTIL_H

class Util {
public:
    enum Direction {
        FORWARD,
        BACK,
        LEFT,
        RIGHT,
        LEFT_DIAGONAL_FORWARD,
        LEFT_DIAGONAL_BACKWARD,
        RIGHT_DIAGONAL_FORWARD,
        RIGHT_DIAGONAL_BACKWARD,
        STOP
    };
};

#endif