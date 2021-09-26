#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
void getNum(T &a, std::string msg = "Enter number\n") { 
    cout << msg;
    cin >> a;
    while(!cin.good()) {
        cin.clear();
        cin.ignore(255,'\n');
        cout << msg;
        cin >> a;
    }
}


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
    void square_rot(void) const;  
    void volume(void) const;
};
