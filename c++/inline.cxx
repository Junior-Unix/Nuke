#include <iostream>
using std::cout;
using std::cin;
using std::endl;

inline double cube( const double );

int main(){

    double sideValue;
    cout << "Enter the side length of your cube: ";
    cin >> sideValue;

    cout << "Volume of cube with side: " << sideValue << " is " << cube( sideValue) << endl;


    return 0;
}

inline double cube( const double side){

    return side * side * side;
}