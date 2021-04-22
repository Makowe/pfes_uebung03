#include <iostream>
#include <cstdio>
#include "../include/PreAllocString.h"

int main() {
    CREATE(Test,50);

    char s[] = "tes23";
    char fmt[] = "abc%s %b";
    Test.AddFormat(fmt, s, -34);
    //Test.AddWhiteSpace();
    Test.AddFormat("abc");

    printf("%s\n",Test_buffer);
    printf("%d %d\n", Test.GetLength(), Test.SizeOf());
    Test.Empty();
    printf("%s\n",Test_buffer);
    printf("%d %d\n", Test.GetLength(), Test.SizeOf());

    //Test = 'a';
    //printf("%s\n",Test_buffer);
    Test = 'a';
    printf("%s\n",Test_buffer);
    printf("%d %d\n", Test.GetLength(), Test.SizeOf());
    Test.AddWhiteSpace();
    Test.AddFormat("123 %x", -5);

    CREATE(Test2, 50);
    Test2 = Test_buffer;
    printf("%s\n",Test2_buffer);
}
