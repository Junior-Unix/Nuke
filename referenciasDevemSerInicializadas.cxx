#include <iostream>
using std::cout;
using std::endl;

int main(){

    int x = 3;
    int &xRef = x;

    cout << "x = " << x << endl << "xRef " << xRef << endl;
    xRef = 7;
    cout << "x = " << x << endl << "xRef = " << xRef << endl;


    return 0;
}