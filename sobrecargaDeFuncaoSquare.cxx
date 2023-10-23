#include <iostream>
using std::cout;
using std::endl;

int square( int );
double square( double );

int main(){

cout << "square of integer: " << square(7) << endl;
cout << "square of double: " << square(7.5) << endl;


    return 0;
}

int square( int x){
    return x * x;
}
double square( double y){
    return y * y;
}