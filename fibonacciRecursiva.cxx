#include <iostream>
using std::cout;
using std::endl;

unsigned long fibonacci(unsigned long);

int main(){

    for (int counter = 0; counter <=10; counter++)
        cout << "fibonacci( " << counter << " ) = " << fibonacci(counter) << endl;



    return 0;
}

unsigned long fibonacci(unsigned long number){

    if((number ==0) || (number ==1))
        return number;
    else 
        return fibonacci(number - 1) + fibonacci(number -2);

}