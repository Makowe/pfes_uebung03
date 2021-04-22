#ifndef UEBUNG03_WRITE_H
#define UEBUNG03_WRITE_H

char* WriteChar(char* dst, const char c);
char* WriteString(char* dst, const void* end, const char* s);
char* WriteString(char* dst, int maxLength, const char* s);

#endif