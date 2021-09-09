#include<iostream>

class Vehicle {
public:
    int passengers;
    int fuelcap;
    int mpg;
    int range();
    Vehicle() {passengers = 228;}
    ~Vehicle();
};

Vehicle::~Vehicle() {
    std::cout << "Misha molodets, object's range = " << range() << std::endl;
}

int Vehicle::range() {
    return fuelcap * mpg;
}

int main() {
    Vehicle minivan;
    Vehicle sportscar;
    sportscar.fuelcap = 32;
    sportscar.mpg = 13;
    int range1, range2;
    std::cout << "Minivan.passengers: " << minivan.passengers 
                << std::endl << minivan.passengers << std::endl;
    minivan.passengers = 7;
    minivan.fuelcap = 12;
    minivan.mpg = 10;
    std::cout << "Minivan.range: " << minivan.range() << std::endl;
}
