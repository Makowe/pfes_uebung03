#ifndef UEBUNG03_FORMATTER_H
#define UEBUNG03_FORMATTER_H

class Formatter {
public:
    static void ToString(char* dst, int number);
    static void ToString(char* dst, unsigned int number);
    static void ToHexString(char* dst, int number);
    static void ToBinString(char* dst, int number);

private:
    static void StringReverse(char* dst, int length);
    static void TwosComplementBin(char* dst, int length);
    static void BinToHex(char* dst);
};

#endif