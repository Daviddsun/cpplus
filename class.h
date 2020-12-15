//
// Created by sun on 2020/12/2.
//

#ifndef CPPLUS_STOCK_H
#define CPPLUS_STOCK_H

#include <string>

class Stock{
private:
    std::string company_;
    long shares_;
    double share_val_;
    double total_val_;
    char * retort();
    void set_tot(){total_val_ = shares_ * share_val_;}
    enum{num = 10}; //  作用域为类的常量
    static const int NUM =10; // 静态存储，而不是存储在对象中；否则对象定义之前是不会创建存储的，没有存储空间；
    double cost[num];
public:
    Stock();
    Stock(const std::string &co, long n, double pr);
//    ~Stock();

    double total() const {return total_val_;}
    void acquire(const std::string & co,long n,double price);
    void buy(long num, double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};
#endif //CPPLUS_STOCK_H
