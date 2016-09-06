#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cstring>
#include "DSString.h"
#include <iostream>


TEST_CASE("String class", "[string]"){

    DSString a;
    DSString b("testString");
    DSString c(a);

    DSString s[10];
    s[0] = DSString("testString");
    s[1] = DSString("testStringLong");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString(s[0]);  //"testString"
    s[7] = DSString("  split  split  split  "); //2 space seperation
    s[8] = DSString("aa");
    s[9] = DSString("testString");



    SECTION("Freebee"){
        REQUIRE(true);
    }

    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("testString"));    //test comparison to DSString
        REQUIRE(s[2] == DSString());                //test with empty DSString
        REQUIRE(s[0] == s[9]);                      //compare to predefined DSString
        REQUIRE(s[2] == "");                        //compare to predefined empty
        REQUIRE(!(s[3] == s[4]));                   //make sure it returns false
        REQUIRE(!(s[0] == s[1]));                   //make sure it's checking length
    }

    SECTION("Assignment operators"){
        DSString str;
        str = "testStringLong";
        REQUIRE(str == s[1]);
        str = "";
        REQUIRE(str == s[2]);
        str = DSString("testString");
        REQUIRE(str == s[0]);
        str = DSString("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DSString("testStringtestString") == s[0]+s[9]);
        REQUIRE(s[2] + s[2] == "");
        REQUIRE(s[5] + s[2] == DSString("\n"));
        REQUIRE(s[0] + s[1] + s[2] == "testStringtestStringLong");
        REQUIRE(s[0] + "moreString" == "testStringmoreString");
    }

    SECTION("Greater than operator"){
        REQUIRE(s[8] > s[0]);           //"aaa" vs "testString
        REQUIRE(s[0] > s[1]);           //"testString" vs "testStringLong"
        REQUIRE(s[3] > s[4]);           //test cap vs non cap
        REQUIRE(s[2] > s[9]);           //test null vs letters
        REQUIRE(s[7] > s[0]);           //test more spaces vs fewer
        REQUIRE(s[8] > "zzz");          //test compare with literal
        REQUIRE(s[8] > "aaa");          //test length with literal
    }

    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[9][-1] == 'g');
        REQUIRE(s[3][-3] == 'I');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }

    SECTION("Size function"){
        REQUIRE(s[0].size() == 10);
        REQUIRE(s[1].size() == 14);
        REQUIRE(s[2].size() == 0);
        REQUIRE((s[9] + s[0]).size() == 20);        //test sum of two strings
        REQUIRE((s[0] + "testString").size() == 20);//test sum of string and literal
    }

    SECTION("Substring function"){
        REQUIRE(s[0].substring(0, 5) == "testS");
        REQUIRE(s[9].substring(0, -3) == "testStri");
        REQUIRE(s[9].substring(0, -1) == s[9]);
        REQUIRE(s[4].substring(0, 4) == "this");
        REQUIRE(s[0].substring(5, 2) == "");
        REQUIRE(s[0].substring(0, 100) == "");          //check out of bounds
        REQUIRE(s[1].substring(-9, -2) == "tringLon");  //negatives are in refrence to the end of the string

    }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

    SECTION("toUpperCase fucntion"){
        std::cout << s[0].toUpperCase();
        REQUIRE(s[0].toUpperCase() == "TESTSTRING");
        REQUIRE(s[4].toUpperCase() == s[3]);
        REQUIRE(s[2].toUpperCase() == s[2]);
    }

    SECTION("toLowerCase function"){
        REQUIRE(s[0].toLowerCase() == "teststring");
        REQUIRE(s[3].toLowerCase() == s[4]);
        REQUIRE(s[2].toLowerCase() == s[2]);
    }

    SECTION("capitalize"){
        DSString temp(s[0]);
        temp.capitalize();
        REQUIRE(temp == "TestString"); //change first char to cap
        temp = s[3];
        temp.capitalize();
        REQUIRE(temp == s[3]);         //do not change a cap letter
        temp = "";
        temp.capitalize();
        REQUIRE(temp == s[2]);         //does nothing to null
    }

}
