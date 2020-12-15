#include <iostream>
#include <cstring>
#include "class.h"

using namespace std;
double extern_company_num =4;
void extern_out();
void placement_new();
void class_test();

int main() {
    double *size = new double(12.123) ;
    cout<<" size = " << size << endl << "  *size = " << *size << endl << endl;
//    placement_new();
    extern_out();
    class_test();

    delete (size);

    return 0;
}
