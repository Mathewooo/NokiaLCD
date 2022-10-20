#include "Pr.hpp"

size_t Pr::write(const uint8_t *buffer, size_t size) {
    size_t n = 0;
    while (size--) {
        if (write(*buffer++)) n++;
        else break;
    }
    return n;
}

size_t Pr::print(const String &s) {
    return write(s.c_str(), s.length());
}

size_t Pr::print(const char str[]) {
    return write(str);
}

size_t Pr::print(char c) {
    return write(c);
}


size_t Pr::println(void) {
    return write("\r\n");
}

size_t Pr::println(const String &s) {
    size_t n = print(s);
    n += println();
    return n;
}

size_t Pr::println(const char c[]) {
    size_t n = print(c);
    n += println();
    return n;
}

size_t Pr::println(char c) {
    size_t n = print(c);
    n += println();
    return n;
}

