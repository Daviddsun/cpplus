//
// Created by sun on 2020/12/6.
//

#include "class.h"
#include "iostream"
using namespace std;

Stock::Stock(const std::string &co, long n, double pr) {
    company_ = co;
    shares_ = n;
    share_val_ = pr;
    set_tot();
    }
char * Stock::retort(){
    char * abc ; // nullptr;
    return abc;
}
void Stock::acquire(const std::string &co, long n, double pr) {
    company_ = co;
    shares_ = n;
    share_val_ = pr;
    set_tot();
    cost[1] = pr * n;
}
void Stock::buy(long num, double price) {
    shares_ += num;
    share_val_ = price;
    set_tot();
}
void Stock::show() const {
//    char * a = retort();
    cout << " company: " << company_ << std::endl
          <<" shares: " << shares_ << std::endl
          <<" price: " << share_val_ << std::endl
          <<" total worth: " << total_val_ << std::endl
        << " cost[1]= " << cost[1];
//           <<" retort char * a : " <<  a << endl;
}
const Stock &Stock::topval(const Stock & s) const{
    if (s.total_val_ > total_val_)
        return s;
    else
        return *this;
}
void class_test() {
    Stock david0 = Stock("sony", 10, 1);
    david0.show();
    cout << david0.total() <<endl;
    david0.acquire("apple",10,5);
    david0.show();
    const int CNT =4;
    Stock mystuff[CNT]={
            Stock("abb", 12, 2),
            Stock("bo", 200, 2),
            Stock("fl",100,10),
            Stock("34",5,1)
    };
    int st;
//    for (st = 0; st < CNT; st++){
//        mystuff[st].show();
//        cout << endl;
//    }

    const Stock * tops = &mystuff[0];
    for (st = 1; st < CNT; st++)
        tops = &tops->topval(mystuff[st]);
    std::cout << "\n most valuable holding:\n";
    tops->show();
}

