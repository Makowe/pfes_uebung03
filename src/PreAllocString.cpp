//
// Created by nicom on 20.04.2021.
//

#include "../include/PreAllocString.h"
#include "../include/Printf.h"
#include "../include/Write.h"

PreAllocString::PreAllocString(char *buffer, size_t size): _buffer(buffer), _length(0), _size(size) {
    if(!validString()) { return; }
    buffer[0] = '\0';
}

void PreAllocString::AddFormat(const char *format, ...) {
    if(!validString()) { return; }
    va_list arguments;
    va_start(arguments, format);
    _length = PrintfArgs(_buffer+_length, _buffer+_size-1, format, arguments) - _buffer;
    va_end(arguments);
}

void PreAllocString::AddWhiteSpace() {
    if(!validString()) { return; }
    _length = WriteString(_buffer+_length, _buffer+_size-1, " ") - _buffer;
}

PreAllocString &PreAllocString::operator=(char rhs) {
    if(!validString()) { return *this; }
    char tempString[2] = "";
    tempString[0] = rhs;
    tempString[1] = '\0';
    _length = WriteString(_buffer, _buffer+_size-1, tempString) - _buffer;
    return *this;
}

PreAllocString &PreAllocString::operator=(const char *rhs) {
    if(!validString()) { return *this; }
    _length = WriteString(_buffer, _buffer+_size-1, rhs) - _buffer;
    return *this;
}

PreAllocString &PreAllocString::operator=(char *const rhs) {
    if(!validString()) { return *this; }
    _length = WriteString(_buffer, _buffer+_size-1, rhs) - _buffer;
    return *this;
}

PreAllocString &PreAllocString::operator+=(char rhs) {
    if(!validString()) { return *this; }
    char tempString[2] = "";
    tempString[0] = rhs;
    tempString[1] = '\0';
    _length = WriteString(_buffer+_length, _buffer+_size-1, tempString) - _buffer;
    return *this;
}

PreAllocString &PreAllocString::operator+=(const char *rhs) {
    if(!validString()) { return *this; }
    _length = WriteString(_buffer+_length, _buffer+_size-1, rhs) - _buffer;
    return *this;
}

const char &PreAllocString::operator[](const int idx) {
    //function can't return any useful value if the string isn't valid. Therefore return reference to local variable
    if(!validString()) { return 0; }
    if(idx > _size-1) return _buffer[_size-1];
    return _buffer[idx];
}

PreAllocString::operator const char *() const {
    return _buffer;
}

PreAllocString::operator const void *() const {
    return _buffer;
}

void PreAllocString::Empty() {
    if(!validString()) { return; }
    _buffer[0] = '\0';
    _length = 0;
}
