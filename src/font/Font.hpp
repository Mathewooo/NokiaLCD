#ifndef NOKIALCD_FONT_H
#define NOKIALCD_FONT_H

#include <string.h>
#include "Characters.hpp"

Character findCorrespondingByte(uint8_t asciiCode) {
    int total = sizeof chars / sizeof *chars;
    Character temp;
    for (int i = 0; i < total; i++) {
        memcpy(&temp, &chars[i], sizeof(Character));
        if (static_cast<int>(temp.character) == asciiCode) return temp;
    }
    memcpy(&temp, &chars[0], sizeof(Character));
    return temp;
}

#endif

