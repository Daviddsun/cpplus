//
// Created by sun on 2020/12/16.
//

#ifndef CPPLUS_STONEWT_H
#define CPPLUS_STONEWT_H
# include <iostream>
class Stonewt{
public:
    double stone_2_lbs = 47.1;

private:
    enum {lbs_per_stone = 14};
    int stones;
    double pounds_left;
    double pounds;
public:
    Stonewt(int stones, double lbs);
    explicit Stonewt(double lbs);
//    Stonewt(double lbs);
    Stonewt();
    ~Stonewt();
    void show_stn() const;
    void show_lbs() const;

};

void test_stones();

void display(const Stonewt &st,int n);

#endif //CPPLUS_STONEWT_H
