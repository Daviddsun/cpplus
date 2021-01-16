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
    StringBad & operator=(const char * s);

    char & operator[](int i);
    const char & operator[](int i) const;
    static int HowMany();
    // friend function
    friend bool operator==(const StringBad &, const StringBad &);
    friend std::ostream & operator<<(std::ostream & os, 
                       const StringBad & st);
    friend bool operator<(const StringBad &st, const StringBad &st2);
    friend bool operator>(const StringBad &st1, const StringBad &st2);
};

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value
void test_sb();
#endif
