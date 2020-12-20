// strngbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
    char * str;                // pointer to string
    int len;                   // length of string
    static int num_strings;    // number of objects
public:
    StringBad(const char * ); // constructor
    StringBad();               // default constructor
    StringBad(const StringBad &);
    ~StringBad();              // destructor
    StringBad & operator=(const StringBad &);
// friend function
    friend std::ostream & operator<<(std::ostream & os, 
                       const StringBad & st);
};

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value
void test_sb();
#endif
