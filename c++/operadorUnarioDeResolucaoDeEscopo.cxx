#include <iostream>
using std::cout;
using std::endl;

int number = 7;

int main(){

    double number = 10.5;

    cout << number << " - " << ::number << endl;
    {
        cout << "\n dentro do bloco do main" << number << endl;
    
    }


    cout << "\n fora do bloco do main" << number << endl;
    cout << "\n fora do bloco do main com ::" << ::number << endl;
    return 0;
}