#include "Cursor.hpp"

#define MAX_ROW 83
#define MAX_COLUMN 5

void Cursor::setCursor(position x, position y) {
    _x = x, _y = y;
}

void Cursor::moveX(position vl) {
    if (vl == 0) return;

    _x++;

    if (_x > MAX_ROW) {
        moveY(1);
        _x = 0;
    }

    moveX(--vl);
}

void Cursor::moveY(position vl) {
    if (vl == 0) return;

    _y++, _x = 0;

    if (_y > MAX_COLUMN)
        _y = 0;

    moveY(--vl);
}

void Cursor::updateCursorPosition(unsigned int xStartPosition) {
    _x = (_x + 1)
            % (xStartPosition + DISPLAY_WIDTH);

    if (_x == 0) {
        _x = xStartPosition,
        _y = (_y + 1) % TOTAL_ROWS;
    }
}

Position Cursor::getPosition() {
    Position currentPosition;
    currentPosition.y = _y, currentPosition.x = _x;
    return currentPosition;
}