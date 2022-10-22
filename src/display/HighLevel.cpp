#include "../NokiaLCD.hpp"
#include "../font/Font.hpp"

/* Printing */

void NokiaLCD::_makeEnoughSpaceForPrinting() {
    _initializeForSendingData();
    if ((COLUMNS_PER_CHAR + _cursor.getPosition().x) < 85)
        return;
    _cursor.moveY(1);
    setCursor(_cursor.getPosition().x, _cursor.getPosition().y);
}

void NokiaLCD::_print(uint8_t character) {
    if (character == NEW_LINE) {
        _cursor.moveY(1);
        return;
    }

    setCursor(_cursor.getPosition().x,_cursor.getPosition().y);
    const Character fontData =
            findCorrespondingChar(character);
    _makeEnoughSpaceForPrinting();

    for (int i = 0; i < COLUMNS_PER_CHAR; i++)
        _transmitInformation(
                fontData.definition[i]
        );

    _transmitInformation(0x0);
    _cursor.moveX(COLUMNS_PER_CHAR + 1);
}

size_t NokiaLCD::write(uint8_t character) {
    _print(character);
    return 1;
}

/* Drawing bitmap */

void NokiaLCD::drawBitmap(const uint8_t *bitmap, size_t bitmapSize) {
    size_t initialX = _cursor.getPosition().x;
    for (size_t i = 0; i < bitmapSize; i++) {
        uint8_t pixel = pgm_read_byte_near(
                bitmap + i
        );
        pixel = _currentDisplayMode == DisplayMode::INVERSE
                ? ~pixel : pixel;
        _initializeForSendingData(), _transmitInformation(pixel),
                _cursor.updateCursorPosition(initialX), setCursor(
                _cursor.getPosition().x, _cursor.getPosition().y
        );
    }
    _transmitInformation(0x0);
}

/* Display clearing */

void NokiaLCD::clear() {
    _initializeForSendingData();
    int i = TOTAL_BITS;
    while (i >= 0) _transmitInformation(0x0), i--;
    setCursor(0, 0);
}

void NokiaLCD::clear(position inRow,
                     position fromColumn,
                     position toColumn) {
    if (fromColumn > toColumn) {
        position temp = fromColumn;
        fromColumn = toColumn;
        toColumn = temp;
    }

    for (int i = fromColumn; i <= toColumn; ++i) {
        setCursor(i, inRow);
        _initializeForSendingData();
        _transmitInformation(0x0);
    }

    setCursor(fromColumn, inRow);
}

/* Internal */

void NokiaLCD::setCursor(position x, position y) {
    _cursor.setCursor(x, y);
    _basicInstruction();
    size_t leastXPositionValue = 128,
            leastYPositionValue = 64;
    _execute(leastXPositionValue + x),
    _execute(leastYPositionValue + y);
}

void NokiaLCD::setContrast(int value) {
    if (value > 127 || value < 0) return;
    _extendedInstruction();
    _execute(CONTR_LEAST_VALUE + value);
}

void NokiaLCD::setTemperatureCoefficient(int value) {
    if (value > 3 || value < 0) return;
    _extendedInstruction();
    _execute(TEMP_LEAST_VALUE + value);
}

void NokiaLCD::setDisplayMode(uint8_t value) {
    _currentDisplayMode = value;
    _basicInstruction(),
            _execute(value);
}

void NokiaLCD::setBiasSystem(uint8_t rate) {
    _extendedInstruction(),
            _execute(rate);
}