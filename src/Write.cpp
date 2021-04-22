#include <cstdio>
#include "../include/Write.h"

char* WriteChar(char* dst, const char c) {
    if(dst == nullptr) return nullptr;

    *dst = c;
    ++dst;
    return dst;
}

char* WriteString(char* dst, const void* end, const char* s) {
    if(dst == nullptr || s == nullptr) return nullptr;

    while(*s && dst < end) {
        *dst = *s;
        ++dst;
        ++s;

    }
    *dst = '\0';
    return dst;
}
