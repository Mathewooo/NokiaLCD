#ifndef NOKIALCD_CURSOR_H
#define NOKIALCD_CURSOR_H

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
        Position getPosition();

    private:
        position _y = 0;
        position _x = 0;
};

#endif
