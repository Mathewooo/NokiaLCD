#include "../NokiaLCD.hpp"

void NokiaLCD::_startTransmission() { digitalWrite(_CE, LOW); }

void NokiaLCD::_endTransmission() { digitalWrite(_CE, HIGH); }

void NokiaLCD::_transmitInformation(uint8_t information) {
    _startTransmission();
    shiftOut(
            _DIN, _CLK,
            MSBFIRST, information
    );
    _endTransmission();
}

void NokiaLCD::_execute(uint8_t command) {
    _initializeForSendingCommand();
    _transmitInformation(command);
}

void NokiaLCD::_initializeForSendingCommand() { digitalWrite(_DC, LOW); }

void NokiaLCD::_extendedInstruction() { _execute(EXTENDED_IN); }

void NokiaLCD::_basicInstruction() { _execute(BASIC_IN); }

void NokiaLCD::_initializeForSendingData() { digitalWrite(_DC, HIGH); }

void NokiaLCD::_reset() {
    digitalWrite(_RST, LOW), digitalWrite(_RST, HIGH);
}