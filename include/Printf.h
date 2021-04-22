#ifndef UEBUNG03_PRINTF_H
#define UEBUNG03_PRINTF_H

#define MAX_ITERS 10000

char* Printf(char* dst, const void* end, const char* fmt, ...);
char* PrintfArgs(char* dst, const void* end, const char* fmt, va_list arguments);

#endif //UEBUNG03_PRINTF_H
