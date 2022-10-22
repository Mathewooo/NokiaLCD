#include "NokiaLCD.hpp"

NokiaLCD::NokiaLCD() {}

NokiaLCD::NokiaLCD(
        int RST, int CE,
        int DC, int DIN,
        int CLK
        ) {
    _RST = RST, _CE = CE, _DC = DC,
    _DIN = DIN, _CLK = CLK;
}

void NokiaLCD::begin() {
    uint8_t pins[5] = {_RST, _CE, _DC, _DIN, _CLK};

    for (int i = 0; i < 5; ++i) {
        pinMode(pins[i], OUTPUT);
    }

    _reset(), clear();
    setDisplayMode(DisplayMode::NORMAL), setBiasSystem(MuxRate::FOURTY);
    setContrast(60);
    _cursor = Cursor();
}