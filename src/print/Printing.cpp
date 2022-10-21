#include "Printing.hpp"

size_t Printing::write(const uint8_t *buffer,
                       size_t size) {
    size_t n = 0;
    while (size--)
        if (write(*buffer++)) n++; else break;
    return n;
}

size_t Printing::print(const String &s) {
    return write(s.c_str(), s.length());
}

size_t Printing::print(char c) {
    return write(c);
}

size_t Printing::println(void) {
    return write("\r\n");
}

size_t Printing::println(const String &s) {
    size_t n = print(s);
    n += println();
    return n;
}

size_t Printing::println(char c) {
    size_t n = print(c);
    n += println();
    return n;
}

