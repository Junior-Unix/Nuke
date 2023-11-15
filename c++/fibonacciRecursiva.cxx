#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <chrono>

unsigned long fibonacci(register unsigned long);

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int n = 0;

    cout << "Insira um numero: ";
    cin >> n;


    for (int counter = 0; counter <= n; counter++) //cuidado com o valor iserido aqui, a recursao pode levar a funcao fibonacci a valores altos muito rápido.
        cout << "fibonacci( " << counter << " ) = " << fibonacci(counter) << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


    std::cout << "A função demorou " << duration.count() << " milissegundos.\n";


    return 0;
}

unsigned long fibonacci(register unsigned long number){

    if((number ==0) || (number ==1))
        return number;
    else 
        return fibonacci(number - 1) + fibonacci(number -2);

}