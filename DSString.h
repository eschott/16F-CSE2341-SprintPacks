#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

class DSString{
    
    private:

        char* str;
        int len;
        int cap;

    public:

        DSString();
        DSString(const char*);
        DSString(const DSString&);

        DSString& operator= (const char*);
        DSString& operator= (const DSString&);
        DSString operator+ (const char*);
        DSString operator+ (const DSString&);
        bool operator== (const char*);
        bool operator== (const DSString&);
        bool operator> (const char*);
        bool operator> (const DSString&);

        char& operator[] (const int);


        int size();
//        DSString substring(int, int);
//        char* c_str();

//        void toLowerCase();
//        void toUpperCase();
//        void cappitalize();

//        friend std::ostream& operator<< (std::ostream&, const DSString&);

        ~DSString();

        //temp


};


#endif
