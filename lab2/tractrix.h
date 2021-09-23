#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;

class Tractrix {
    double a;    
    double diff(double y) const;
    double rediff(double f) const {return a / sqrt(f*f + 1);}
    double function(double y) const;
public:
    void set_a(double value) {a = value;}
    double get_a() const {return a;}
    double func3(double arc) const;
    void len(double arc) const;
    void radius(double arc) const;
    void square(void) const;
     

};
