//
// Created by sun on 2020/12/10.
//
#include <iostream>
#include "operator.h"
Time::Time() {
    hours = minutes = 0;
}
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}
void Time::add_hr() {
    hours += h;
}
void Time::add_minutes( int m) {
    minutes += m;
    hours += m/60;
    minutes %= 60;
}
Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = t.hours + sum.minutes /60;
    sum.minutes %= 60;
    return sum;
}
void Time::show() const {
    std::cout << hours << "hours: " << minutes << "minutes";
}