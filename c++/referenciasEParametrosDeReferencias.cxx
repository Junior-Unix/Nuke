#include <iostream>
using std::cout;
using std::endl;

int squareByValue(int);
void squareByReference(int &);

int main(){

    int x = 2;
    int z = 4;

    cout << "x = " << x << " antes squareByValue\n";
    cout << "Valor retornado squareByValue: " << squareByValue(x) << endl;
    cout << "x = " << x << " after suareByValue\n" << endl;

    cout << "z = " << z << " antes de squareByReference" << endl;
    cout << "Valor retornado squareByReference: " << squareByReference(z) << endl;
    cout << "z " << z << " depoir de squareByReference" << endl;



    return 0;
}

int squareByValue(int number){
    return number *+ number;
}

void squareByReference(int &numberRef){
    numberRef *= numberRef;
}