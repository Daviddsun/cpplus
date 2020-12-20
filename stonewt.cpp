//
// Created by sun on 2020/12/16.
//

#include "stonewt.h"
#include <iostream>
using std::cout;

Stonewt::Stonewt(double lbs) {
    stones = lbs / lbs_per_stone;
    pounds_left = int(lbs) % lbs_per_stone + lbs -int(lbs);
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
    stones = stn;
    pounds_left = lbs;
    pounds =  stn * lbs_per_stone +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stones = pounds = pounds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stones << " stone, " << pounds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

void test_stones(){
Stonewt incognito(275); // uses constructor to initialize
Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
Stonewt taft(21, 8);

cout << "The celebrity weighed ";
incognito.show_stn();
cout << "The detective weighed ";
wolfe.show_stn();
cout << "The President weighed ";
taft.show_lbs();
incognito = Stonewt(276.8);      // uses constructor for conversion
taft = Stonewt(325);             // taft = 325;  same as taft = Stonewt(325);
cout << "After dinner, the celebrity weighed ";
incognito.show_stn();
cout << "After dinner, the President weighed ";
taft.show_lbs();
display(taft, 2);
cout << "The wrestler weighed even more.\n";
display((Stonewt)422, 4);
cout << "No stone left unearned\n";
// std::cin.get();

}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}