#include "../include/Formatter.h"

void Formatter::ToString(char *dst, int number) {
    if(dst == nullptr) return;

    bool negative = false;
    if(number < 0) {
        negative = true;
        number *= -1;
    }
    int numChars = 0;

    do {
        int digit = number % 10;
        //convert to ASCII character
        dst[numChars] = static_cast<char>(digit + 48);
        ++numChars;
        number /= 10;
    } while(number);

    if(negative) {
        dst[numChars] = '-';
        ++numChars;
    }
    dst[numChars] = '\0';
    StringReverse(dst, numChars);
}

void Formatter::ToString(char *dst, unsigned int number) {
    if(dst == nullptr) return;

    int numChar = 0;

    do {
        unsigned int digit = number % 10;
        //convert to ASCII character
        dst[numChar] = static_cast<char>(digit + 48);
        ++numChar;
        number /= 10;
    } while(number);

    dst[numChar] = '\0';
    StringReverse(dst, numChar);
}

void Formatter::ToHexString(char *dst, int number) {
    if(dst == nullptr) return;

    if(number >= 0) {
        int numChar = 0;

        do {
            int digit = number % 16;
            //convert to ASCII character
            if(digit < 10) { dst[numChar] = static_cast<char>(digit + 48); } //0-9
            else { dst[numChar] = static_cast<char>(digit + 87); } //a-f

            ++numChar;
            number /= 16;
        } while(number);

        dst[numChar] = 'x';
        dst[numChar + 1] = '0';
        dst[numChar + 2] = '\0';
        numChar += 2;
        StringReverse(dst, numChar);
    }
    else {
        ToBinString(dst, number);
        dst[1] = 'x';   // change 0b to 0x
        BinToHex(dst+2);
    }
}

void Formatter::ToBinString(char *dst, int number) {
    if(dst == nullptr) return;

    if(number >= 0) {
        int numChar = 0;

        do {
            int digit = number % 2;
            //convert to ASCII character
            dst[numChar] = static_cast<char>(digit + 48);
            ++numChar;
            number /= 2;
        } while(number);

        dst[numChar] = 'b';
        dst[numChar + 1] = '0';
        dst[numChar + 2] = '\0';
        numChar += 2;

        StringReverse(dst, numChar);
    }
    else {
        number *= -1;

        int numChar = 0;

        do {
            int digit = number % 2;
            //convert to ASCII character
            dst[numChar] = static_cast<char>(digit + 48);
            ++numChar;
            number /= 2;
        } while(number);

        //fill the rest with zeroes
        while(numChar < static_cast<int>(sizeof(int) * 8)) {
            dst[numChar] = '0';
            ++numChar;
        }
        dst[numChar] = 'b';
        dst[numChar + 1] = '0';
        dst[numChar + 2] = '\0';
        numChar += 2;
        StringReverse(dst, numChar);
        TwosComplementBin(dst+2, sizeof(int)*8);   //add 2 to skip the string "0b"
    }
}

void Formatter::StringReverse(char *dst, int length) {

    if(dst == nullptr) return;

    for(int i = 0; i<length/2; ++i) {
        char tmpChar = dst[i];
        dst[i] = dst[length-1-i];
        dst[length-1-i] = tmpChar;
    }
}

void Formatter::TwosComplementBin(char *dst, int length) {
    if(dst == nullptr) return;
    //swap every Bit
    for(int i = 0; i<length; ++i) {
        if (dst[i] == '0') dst[i] = '1';
        else dst[i] = '0';
    }

    //add 1
    for(int i = length-1; i>=0; --i) {
        if(dst[i] == '0') {
            dst[i] = '1';
            break;
        }
        else {
            dst[i] = '0';
        }
    }
}

void Formatter::BinToHex(char *dst) {
    if(dst == nullptr) return;

    for(int i = 0; i < 8; ++i) {
        int currentNumber = 0;
        for(int j = 0; j < 4; ++j) {
            if(dst[4*i + j] == '1') currentNumber += (1 << (3-j));
        }
        if(currentNumber < 10) dst[i] = static_cast<char>(currentNumber + 48); //0-9
        else dst[i] = static_cast<char>(currentNumber + 87); //a-f
    }
    dst[8] = '\0';
}
