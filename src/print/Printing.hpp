#ifndef NOKIALCD_PRINTING_HPP
#define NOKIALCD_PRINTING_HPP

#include "WString.h"

class Printing {
public:
    virtual size_t write(uint8_t) = 0;

    size_t write(const char *str) {
        if (str == nullptr) return 0;
        return write(
                (const uint8_t *) str, strlen(str)
        );
    }

    virtual size_t write(const uint8_t *buffer,
                         size_t size);

    size_t write(const char *buffer,
                 size_t size) {
        return write(
                (const uint8_t *) buffer, size
        );
    }

    size_t print(const String &);
    size_t print(char);

    size_t println(const String &s);
    size_t println(char);
    size_t println();
};

#endif
