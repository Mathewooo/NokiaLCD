#ifndef NOKIA_LCD
#define NOKIA_LCD

#include "Arduino.h"
#include "constants/DisplayMode.h"
#include "constants/MuxRate.hpp"
#include "cursor/Cursor.hpp"
#include "Defs.hpp"
#include "print/Pr.hpp"

class NokiaLCD : public Pr {
public:
    NokiaLCD();

    /**
     * @class NokiaLCD()
      * @param int RST
      * @param int CE
      * @param int DC
      * @param int DIN
      * @param int CLK
     * @details Initializes the display with digital pins.
     * DataSheet for the display:
     * (https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)
    */
    NokiaLCD(int RST, int CE, int DC, int DIN, int CLK);

    /**
     * @fn setContrast()
      * @param unsigned short value
     * @details Sets contrast for the display, value - (From 0 to 127),
     * by default it's 60. To find out more about setting contrast see:
     * (https://pacificdisplay.com/lcd_view_angles.htm &
     * https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)
    */
    void setContrast(int value);

    /**
     * @fn setTemperatureCoefficient()
      * @param unsigned short value
     * @details Sets TemperatureCoefficient, value - (From 0 to 3),
     * we sometimes need to change voltage for display in different temperatures,
     * find out more about it here:
     * (https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)
    */
    void setTemperatureCoefficient(int value);

    /**
    * @fn clear()
    * @details Clears the whole display
    */
    void clear();

    /**
    * @fn clear()
     * @param position inRow
     * @param position fromColumn
     * @param position toColumn
    * @details Clears a portion of the display
    */
    void clear(position inRow, position fromColumn, position toColumn);

    /**
     * @fn setCursor()
      * @param position x
      * @param position y
     * @details Sets Cursor to desired (x and y)
    */
    void setCursor(position x, position y);

    /**
    * @fn setDisplayMode()
     * @param display_mode value
    * @details Sets display mode,
     * modes(BLANK, NORMAL, ALL_SEGMENTS_ON, INVERSE)
    */
    void setDisplayMode(uint8_t mode);

    /**
    * @fn setBiasSystem()
     * @param mux_rate value
    * @details Sets bias system with mux rate
     * which then sets bias angle (viewing angle),
     * read more here: (https://pacificdisplay.com/lcd_view_angles.htm)
    */
    void setBiasSystem(uint8_t rate);

    virtual size_t write(uint8_t);

private:
    void _print(uint8_t character);
    void _startTransmission();
    void _endTransmission();
    void _transmitInformation(uint8_t information);
    void _execute(uint8_t command);
    void _extendedInstruction();
    void _basicInstruction();
    void _reset();
    void _initializeForSendingCommand();
    void _initializeForSendingData();
    void _makeEnoughSpaceForPrinting();

    unsigned short _RST;
    unsigned short _CE;
    unsigned short _DC;
    unsigned short _DIN;
    unsigned short _CLK;

    Cursor _cursor;
};

#endif

