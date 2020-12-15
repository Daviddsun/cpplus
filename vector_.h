//
// Created by sun on 2020/12/15.
//

#ifndef CPPLUS_VECTOR__H
#define CPPLUS_VECTOR__H

namespace VECTOR{
    class Vector{
        enum Mode{RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double  n1,double n2, Mode form=RECT);
        void reset(double  n2, double n2, Mode form=RECT);
        ~Vector();
        void Polar_mode();
        void rect_mode();

        vector void operator+(const vector & b) const;
        vector void operator-(const vector & b) const;
        vector void operator-()const;
        vector void operator*(double n)const;

        friend vector operator*(double n, const vector &a);
        friend std::ostream & operator



    };
}
#endif //CPPLUS_VECTOR__H
