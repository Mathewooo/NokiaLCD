#ifndef NOKIALCD_FONT_H
#define NOKIALCD_FONT_H

#include <string.h>
#include "Characters.hpp"

Character findCorrespondingChar(uint8_t asciiCode) {
    Character result;
    for (int i = 0; i < sizeof chars / sizeof *chars; i++) {
        memcpy_P(&result, &chars[i], sizeof(Character));
        if (static_cast<int>(result.character) == asciiCode)
            return result;
    }
    memcpy_P(&result, &chars, sizeof(Character));
    return result;
}

#endif

