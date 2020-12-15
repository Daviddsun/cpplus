//
// Created by sun on 2020/12/9.
//

#ifndef CPPLUS_OPERATOR_H
#define CPPLUS_OPERATOR_H
class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m=0);
    void add_minutes(int m);
    void add_hr();
    Time operator + (const Time &t) const;
    void show() const;
};

#endif //CPPLUS_OPERATOR_H
