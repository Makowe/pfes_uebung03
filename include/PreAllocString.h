#ifndef UEBUNG03_PREALLOCSTRING_H
#define UEBUNG03_PREALLOCSTRING_H

#include <stdio.h>
#include <cstdarg>

//creates char buffer of given size and passes it to constructor of PreAllocString
#define CREATE(varName,size) char varName##_buffer[size]="";\
PreAllocString varName(varName##_buffer, size)

class PreAllocString {
public:

    PreAllocString(char* buffer, size_t size);

    /* Current number of characters in string */
    size_t GetLength() const { return _length; }

    /* Maximum number of characters possible */
    constexpr size_t SizeOf() { return _size; }

    /* Empty the string, set length field to zero */
    void Empty();

    void AddFormat(const char* format, ...);
    void AddWhiteSpace();

    operator const char *() const;
    operator const void *() const;
    const char & operator [] (const int idx);

    PreAllocString& operator = (char rhs);
    PreAllocString& operator = (const char * rhs);
    PreAllocString& operator = (char * const rhs);

    PreAllocString& operator += (char rhs);
    PreAllocString& operator += (char const * rhs);

private:
    bool validString() { return _buffer != nullptr && _size > 0; }

    char* const _buffer;
    size_t _length;
    const size_t _size;
};


#endif //UEBUNG03_PREALLOCSTRING_H
