#include"tractrix.h"

inline double Tractrix::function(double y) const {
    return (a * log((a + sqrt(a*a - y*y))/y) - sqrt(a*a - y*y)); 
}
inline double Tractrix::diff(double y) const {
    return sqrt(a*a - y*y) / y;
}

double Tractrix::func3(double arc) const {
    arc = 1 / tan(arc);
    int f = 1;
    if (arc > 0) 
        f = -1;
    double y = a / sqrt(arc*arc +1);
    double x = Tractrix::function(y);
    cout << "x = " << x*f << endl;
    cout << "y = " << y << endl;
    return x; //sdfklhflwethwo;eihqorwrOUGIUGIUG
}

void Tractrix::len(double arc) const {
    arc = 1 / tan(arc);
    double y = a / sqrt(arc*arc +1);
    double len = a * log(a / y); 
    cout << "Length of curve = " << len << endl;
}

void Tractrix::radius(double arc) const {
    arc = 1 / tan(arc);
    double y = a / sqrt(arc*arc +1);
    double x = Tractrix::function(y);
    cout << "Radius = " << a * tan(y / x) << endl;
}

void Tractrix::square() const {
    cout << "Square is: " << 3.14 * a * a / 2 << endl;
}


