#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

unsigned long factorial(unsigned long);

int main(){

    int n = 0;

    cout << "Insira um numero: ";
    cin >> n;

    for (int counter = 0; counter <= n; counter++){
        cout << setw(2) << counter << "! = " << factorial(counter) << endl;
    }



    return 0;
}

unsigned long factorial(unsigned long number){
    unsigned long result = 1;

    for (unsigned long i = number; i >= 1; --i)
        result *= i;

    return result;
}