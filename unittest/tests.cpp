#include <cstring>
#include "catch.hpp"
#include "../include/PreAllocString.h"

TEST_CASE( "legal operations", "PreAllocString" ) {
    SECTION("generate") {
        CREATE(Test, 50);
        REQUIRE(Test.SizeOf() == 50);
        REQUIRE(Test.GetLength() == 0);
        REQUIRE(strcmp(Test_buffer, "") == 0);
    }
    SECTION("methods") {
        CREATE(Test, 50);
        Test.AddFormat("123 %d %x %s", 23, -45, "test");
        REQUIRE(strcmp(Test_buffer, "123 23 0xffffffd3 test") == 0);
        REQUIRE(Test.GetLength() == 22);
        Test.AddWhiteSpace();
        REQUIRE(strcmp(Test_buffer, "123 23 0xffffffd3 test ") == 0);
        REQUIRE(Test.GetLength() == 23);
        Test.Empty();
        REQUIRE(strcmp(Test_buffer, "") == 0);
        REQUIRE(Test.GetLength() == 0);
    }
    SECTION("operators") {
        CREATE(Test, 50);
        Test = 'a';
        REQUIRE(Test.GetLength() == 1);
        REQUIRE(strcmp(Test_buffer, "a") == 0);
        Test += 'b';
        REQUIRE(Test.GetLength() == 2);
        REQUIRE(strcmp(Test_buffer, "ab") == 0);
        Test = 'c';
        REQUIRE(Test.GetLength() == 1);
        REQUIRE(strcmp(Test_buffer, "c") == 0);
        Test = "test";
        REQUIRE(Test.GetLength() == 4);
        REQUIRE(strcmp(Test_buffer, "test") == 0);
        Test += "string";
        REQUIRE(Test.GetLength() == 10);
        REQUIRE(strcmp(Test_buffer, "teststring") == 0);
        REQUIRE(Test[4] == 's');
    }
    SECTION("conversion") {
        CREATE(Test, 50);
        REQUIRE(*Test == Test[0]);
    }
}

TEST_CASE( "illegal operations", "PreAllocString" ) {
    SECTION("prevent overflow") {
        CREATE(Test, 10);
        Test.AddFormat("12345678901234567890");
        REQUIRE(Test.GetLength() == 9);
        REQUIRE(strcmp(Test_buffer,"123456789") == 0);
        Test.AddWhiteSpace();
        REQUIRE(Test.GetLength() == 9);
        REQUIRE(strcmp(Test_buffer,"123456789") == 0);
        Test += 'a';
        REQUIRE(Test.GetLength() == 9);
        REQUIRE(strcmp(Test_buffer,"123456789") == 0);
    }
}