// strngbad.cpp -- StringBad class methods
#include <cstring>
#include <iostream> // string.h for some
#include "strngbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);             // set size
    str = new char[len + 1];          // allot storage
    std::strcpy(str, s);              // initialize pointer
    num_strings++;                    // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n";    // For Your Information
}

StringBad::StringBad()                // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");          // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";  // FYI
}

StringBad::~StringBad()               // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";    // FYI
    --num_strings;                    // required
    cout << num_strings << " left\n"; // FYI
    delete [] str;                    // required
}

StringBad::StringBad(const StringBad &st){
    num_strings += 1;
    len = st.len;
    str = new char [len+1];
    std::strcpy(str, st.str);
    std::cout << num_strings << " :  str  \"" << str << " \"  created" <<std::endl;
}
int StringBad::HowMany() {
    return num_strings;
}

StringBad & StringBad::operator=(const StringBad &st) {
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
StringBad & StringBad::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}
char & StringBad::operator[](int i)
{
    return str[i];
}
const char & StringBad::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator==(const StringBad &str1, const StringBad &str2){
    return (std::strcmp(str1.str, str2.str) == 0);
}

bool operator<(const StringBad &st1, const StringBad &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const StringBad &st1, const StringBad &st2)
{
    return st2 < st1;
}
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}


void test_sb()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports; // 拷贝构造函数
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1; // 赋值构造函数；
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    StringBad string_1("sdf");
    cout << string_1[2]<<endl;
    }
    cout << "End of main()\n";
    // std::cin.get();
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
