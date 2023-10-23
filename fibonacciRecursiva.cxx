#include <iostream>
using std::cout;
using std::cin;
using std::endl;

unsigned long fibonacci(unsigned long);

int main(){

    int n = 0;

    cout << "Insira um numero: ";
    cin >> n;

    for (int counter = 0; counter <= n; counter++) //cuidado com o valor iserido aqui, a recursao pode levar a funcao fibonacci a valores altos muito rápido.
        cout << "fibonacci( " << counter << " ) = " << fibonacci(counter) << endl;

    



    return 0;
}

unsigned long fibonacci(unsigned long number){

    if((number ==0) || (number ==1))
        return number;
    else 
        return fibonacci(number - 1) + fibonacci(number -2);

}