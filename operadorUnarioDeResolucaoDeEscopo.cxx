#include <iostream>
using std::cout;
using std::endl;

int number = 7;
int &numberRef = ::number;

int main(){

    double number = 10.5;

    cout << number << " - " << ::number << endl;
    {
        cout << "\n dentro do bloco do main" << number << endl;
    
    }


    cout << "\n fora do bloco do main" << number << endl;
    cout << "\n fora do bloco do main com ::" << ::number << endl;
    numberRef = 10;
    cout << "\n dentro do bloco do main $numberRef: " << ::number << endl;
    cout << "\n &number" << &number << endl;
    cout << "\n &numerRef" << &numberRef << endl;
    return 0;
}