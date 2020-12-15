//
// Created by sun on 2020/12/6.
//
#include <iostream>
using namespace std;

struct chaff{
    char dross[20];
    int slag;
};

const int buf = 5;
const int N = 3;
char buffer1[buf];                  // char format
void placement_new(){
    int *p3, *p4;

    cout << "\n calling new and placement new a 1st time: \n";
    p3 = new int[N];
    p4 = new (buffer1) int[N];
    int i;
    for ( i = 0; i < N; i++)
        p3[i] = p4[i] = 1000 + 20 * i;
    cout << "Memory address :\n" << "  heap: " << p3 << "\n  static: " << (void*) buffer1 << "\n  p4: " << p4 <<  endl; //void * 强制类型转换 char
    cout << "Memory content : \n" ;
    for (i = 0; i< N; i++){
        cout << p3[i] << " at " << &p3[i] << ";  ";
        cout << p4[i] << " at " << &p4[i] << endl;
    }

    cout << "\n calling new and placement new a 2nd time: \n"; //
    p3 = new int[N];                     // new 查找新的内存块
    p4 = new (buffer1) int [N];          // 定位new 分配与以前相同的内存块；
    for ( i = 0; i < N; i++)
        p3[i] = p4[i] = 1000 + 40 * i;
    cout << "Memory address :\n" << "  heap: " << p3 << "\n  static: " << (void*) buffer1 << "\n  p4: " << p4 <<  endl;
    cout << "Memory content : \n" ;
    for (i = 0; i< N; i++){
        cout << p3[i] << " at " << &p3[i] << ";  ";
        cout << p4[i] << " at " << &p4[i] << endl;
    }

    cout << "\n calling new and placement new a 3rd time: \n";
    p3 = new int[N];
    p4 = new (buffer1 + N * sizeof(int)) int [N]; //buffer1 开头算起的偏移量，将重新分配内存；
    for ( i = 0; i < N; i++)
        p3[i] = p4[i] = 1000 + 60 * i;
    cout << "Memory address :\n" << "  heap: " << p3 << "\n  static: " << (void*) buffer1 << "\n  p4: " << p4 <<  endl;
    cout << "Memory content :\n" ;
    for (i = 0; i< N; i++){
        cout << p3[i] << " at " << &p3[i] << "; ";
        cout << p4[i] << " at " << &p4[i] << endl;
    }

    delete [] p3; //delete 只能用于指向常规new运算符分配的堆heap内存；
//    delete [] p4; //buffer位于delete 管辖区域之外；
}
