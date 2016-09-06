#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

class DSString{
    
    private:

        char* str;      //data held by string. actual string stored here
        int len;        //length of the string. how many chars compose the string
        int cap;        //capacity of the string. How much space can be used before alocating more.

    public:

        DSString();
        DSString(const char*);
        DSString(const DSString&);

        DSString& operator= (const char*);      //asignemt opperator using char array
        DSString& operator= (const DSString&);  //copy constructor
        DSString operator+ (const char*);       //addition operator adds a char array
        DSString operator+ (const DSString&);   //addition operator adds another string
        bool operator== (const char*);          //equality operator comparing to char array
        bool operator== (const DSString&);      //equality operator comparing two strings
        bool operator> (const char*);           //greater than operator returns true is sorted with char array
        bool operator> (const DSString&);       //greater than operator returns true is sorted with string

        char operator[] (const int);            //subscript operator returns the char at that pos in the string


        int size();                     //returns the length of the string
        DSString substring(int, int);   //returns the chars between the given values (negatives in reference to end of string
        char* c_str();                  //returns the string as a c_string

        DSString toLowerCase();         //does not change string, just returns lower case value
        DSString toUpperCase();         //does not change string, just returns upper case value
        DSString& capitalize();

        friend std::ostream& operator<< (std::ostream&, const DSString&);   //overloaded insertion operator for cout and the like

        ~DSString();                    //destructor (!deconstructor)



};


#endif
