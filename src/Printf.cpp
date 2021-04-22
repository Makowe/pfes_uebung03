#include <cstdarg>

#include "../include/Printf.h"
#include "../include/Write.h"
#include "../include/Formatter.h"

char* Printf(char* dst, const void* end, const char* fmt, ...) {
    if(dst == nullptr || end == nullptr || fmt == nullptr) return nullptr;
    if(dst >= end) return dst;

    va_list arguments;
    va_start(arguments, fmt);
    return PrintfArgs(dst, end, fmt, arguments);
    va_end(arguments);
}

char* PrintfArgs(char* dst , const void* end , const char* fmt , va_list arguments) {
    if(dst == nullptr || end == nullptr || fmt == nullptr) return nullptr;
    if(dst >= end) return dst;

    int i = 0;
    while(fmt[i] && dst < end) {
        if(fmt[i] != '%') {
            dst = WriteChar(dst, fmt[i]);
            ++i;
        }
        else {
            char tempString[40] = "";

            switch(fmt[i+1]) {
                case 'd':
                    Formatter::ToString(tempString, va_arg(arguments, int));
                    dst = WriteString(dst, end, tempString);
                    break;
                case 'u':
                    Formatter::ToString(tempString, va_arg(arguments, unsigned int));
                    dst = WriteString(dst, end, tempString);
                    break;
                case 'x':
                    Formatter::ToHexString(tempString, va_arg(arguments, int));
                    dst = WriteString(dst, end, tempString);
                    break;
                case 'b':
                    Formatter::ToBinString(tempString, va_arg(arguments, int));
                    dst = WriteString(dst, end, tempString);
                    break;
                case 'c':
                    dst = WriteChar(dst, va_arg(arguments, int));
                    break;
                case 's':
                    dst = WriteString(dst, end, va_arg(arguments, char*));
                    break;
                case '%':
                    dst = WriteChar(dst, '%');
                    break;
                default:
                    //wrong character
                    *dst = '\0';
                    return dst;
            }
            i += 2;
        }
    }
    *dst = '\0';
    return dst;
}