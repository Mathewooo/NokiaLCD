#ifndef NOKIALCD_CURSOR_H
#define NOKIALCD_CURSOR_H

#include "../Defs.hpp"

typedef unsigned short position;

struct Position {
    position y;
    position x;
};

class Cursor {
    public:
        void setCursor(position x, position y);
        void moveX(position vl);
        void moveY(position vl);
        void updateCursorPosition(unsigned int xStartPosition);
        Position getPosition() const;

    private:
        position _y = 0;
        position _x = 0;
};

#endif
