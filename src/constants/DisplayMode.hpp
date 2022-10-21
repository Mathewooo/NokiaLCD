#ifndef NOKIALCD_DISPLAY_MODE_H
#define NOKIALCD_DISPLAY_MODE_H

namespace DisplayMode {
    constexpr uint8_t
        BLANK = 0x8,
        NORMAL = 0xc,
        ALL_SEGMENTS_ON = 0x9,
        INVERSE = 0xd;
}

#endif
