#include<iostream>
#include"DSString.h"

///----constructors----///

//default constructor initializes to 0s and nullptr
DSString::DSString(){

    str = nullptr;
    len = 0; 
    cap = 0;

}

//constructor takes literal char* as argument
DSString::DSString(const char* s){

    len = 0;
    while(s[len] != '\0')          //determine how long the cstring is
        len++;

    str = new char[len];            //create array of appropriate length
    cap = len;
    for(int i = 0; i < len; i++)    //copy the cstring into the str array
        str[i] = s[i];

}

//Copy constructor takes DSString as argument
DSString::DSString(const DSString& s){

    if(s.str != nullptr){           //check if str actual holds info
        str = new char[s.cap];      //create new char* for new DSString
        for(int i = 0; i < s.cap; i++)//copy str information to new char*
            str[i] = s.str[i];
    }
    else
        str = nullptr;              //copy blank info
    len = s.len;                    //copy len and cap regaurdless of str content
    cap = s.cap;

}

//destructor (not deconstructor!)
DSString::~DSString(){

    if(str != nullptr)      //delete str only if it exists
        delete[] str;       //avoiding seg faults!
    
}

///----asignment operators----///

//asignment of a DSString using char* as argument
DSString& DSString::operator= (const char* s){

    if(*this == s)
        return *this;       //if they're already equal, do nothing


    len = 0;
    while(s[len] != '\0')    //find length of s
        len++;

    if(len > cap){          //if char* is longer than capacity
        delete[] str;       //delete the old str
        str = new char[len]; //and alocate new memory for the longer string
        cap = len;
    }

    for(int i = 0; i < len; i++)    //copy data over
        str[i] = s[i];


    return *this;

}

//asignment operator taking DSString as argument
DSString& DSString::operator= (const DSString& s){

    if(*this == s)
        return *this;       //if already equal, do nothing


    if(s.str != nullptr){           //check if str holds data

        if(s.len > cap){            //if the new string is longer than current capacity
            delete[] str;           //delete old str memory
            str = new char[s.len];    //and alocate new mem
            cap = s.len;              //and adjust capacity
        }

        for(int i = 0; i < s.len; i++)  //copy str data over
            str[i] = s.str[i];
    }
    else
        str = nullptr;

    len = s.len;


    return *this;

}

///----addtion operator----///

//addition operator adds string to char* literal
DSString DSString::operator+ (const char* rhs){

    return *this + DSString(rhs);

}

//addtion operator adds two strings together
DSString DSString::operator+ (const DSString& rhs){

    if(rhs.str == nullptr)      //if the adden string is empty
        return *this;           //return this string


    char* sum = new char[len + rhs.len + 1];    //create a new char* with length of both DSStrings
                                                //leave room for null termination
    for(int i = 0; i < len; i++)
        sum[i] = str[i];                    //copy data from first string

    for(int i = len; i < len + rhs.len; i++)
        sum[i] = rhs.str[i - len];          //copy data from second string with this.len as offset

    sum[len + rhs.len] = '\0';              //end with null termination

    return DSString(sum);

}

///----Eqaulity operators----///

//check equality with literal char*
bool DSString::operator== (const char* s){

    if(s[len] != '\0')              //check for same length
        return false;

    for(int i = 0; i < len; i++){   //check for same content
        if(str[i] != s[i])
            return false;
    }

    return true;                    //equal if both tests were passed

}

//check equality of two strings
bool DSString ::operator== (const DSString& s){

    if(len != s.len)                //check length of strings
        return false;

    for(int i = 0; i < len; i++){
        if(str[i] != s.str[i])
            return false;           //check content of string
    }

    return true;                    //if both tests are passed, they're equal
}

///----greater than operator----///

//conpares two strings and returns bool if they're in order
bool DSString::operator> (const DSString& rhs){

    if(*this == rhs)        //if the strings are the same
        return true;        //they're considered sorted

    //check if either string is empty
    if(str == nullptr)
        return false;
    if(rhs.str == nullptr)
        return true;

    //check if chars are equal and sort accordingly
    int i = 0;
    char left, right;

    do{

        //checks if one of the strings has exhausted it's length. Shorter has presidence
        if(i > len && i <= rhs.len)     //lhs == rhs but rhs is longer
            return false;
        if(i > rhs.len && i <= len)     //lhs == rhs but lhs is longer
            return true;

        left = str[i];
        right = rhs.str[i];

        if(left == right) {

            //checks case if the chars are the same. Upper-case presidence
            if(right < 97 && left  >= 97)       //right is cap, left is lower
                return true;
            if(left <  97 && right >= 97)       //left is cap, right is lower
                return false;
        }

        i++;

   } while(left == right);

    //checks alphabatization
    if(left < right)
        return false;
    else
        return true;
}

//compares string with char* literal and returns bool if sorted
bool DSString::operator> (const char* rhs){

    return *this > DSString(rhs);

}

///----[] operator----///
char DSString::operator[] (const int pos){

    if(pos < len && pos > 0)        //if pos is positive and in bounds
        return str[pos];            //return the char at that pos

    if(pos < 0 && pos + len >= 0)    //if pos is negative and in bounds
        return str[len + pos];      //return char at pos from end

    else return '\0';

}

///----operator<<----///

//string extraction operator overloading
std::ostream& operator<< (std::ostream& os, const DSString& st){

    for(int i = 0; i < st.len; i ++)
        std::cout << st.str[i];

    return os;
}

///----get functions----///

//returns the length of the string
int DSString::size(){
    
    return len;

}

//prints out all chars between two parameters
DSString DSString::substring(int s, int f){

    if(s < 0)
        s = s + len;
    if(f < 0)
        f = f + len + 1;

    //asign length to temp and check validity
    int templen = f - s;
    if(templen <= 0 || f > len)
        return DSString();

    char* temp = new char[templen + 1];     //dynamicaly alocate with room for \0
    for(int i = 0; i < templen; i++)
        temp[i] = str[s + i];               //copy str with s offset
    temp[templen] = '\0';                     //terminate cstr

    return DSString(temp);
}

//
char* DSString::c_str(){

    char* temp = new char[len + 1];         //dynamically alocate char* w/ room for \0
    for(int i = 0; i < len; i ++)
        temp[i] = str[i];
    temp[len] = '\0';

    return temp;

}


///----changing case----///

//returns the lower case verson of the string
DSString DSString::toLowerCase(){

    char* temp = new char[len + 1];         //dynamically alocate char* for return string

    for(int i = 0; i < len; i++){
        if(65 <= str[i] && str[i] <= 90)
            temp[i] = str[i] + 32;          //change to lower case
        else
            temp[i] = str[i];               //is already lower case or other char
    }

    temp[len] = '\0';                       //add null terminator

    return DSString(temp);

}

DSString DSString::toUpperCase(){

    char* temp = new char[len + 1];         //dynamically alocate char* for return string

    for(int i = 0; i < len; i++){
        if(97 <= str[i] && str[i] <= 122)
            temp[i] = str[i] - 32;          //change to lower case
        else
            temp[i] = str[i];               //is already lower case or other char
    }

    temp[len] = '\0';                       //add null terminator

    return DSString(temp);

}

//changes the first letter to a captital one
DSString& DSString::capitalize(){

    if(97 <= str[0] && str[0] <=122)
        str[0] -= 32;

    return *this;

}

