#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int square(int);

int main(){

    int a{0};

    cout << "Digite o valor de a: " << endl;
    cin >> a;
    cout << a << " squared: " << square(a) << endl;   
    
    
    return 0;
}

int square(int x){
    return x * x;
}