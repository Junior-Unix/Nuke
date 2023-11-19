#include <iostream>
using std::cout;
using std::endl;

inline int boxVolume(int length = 1, int widht = 1, int heigth = 1);

int main(){

    cout << "Valor padrao do volume da caixa é: " << boxVolume();
    cout << "\nValor padrao do volume da caixa é: " << boxVolume(10);
    cout << "\nValor padrao do volume da caixa é: " << boxVolume(10,5);
    cout << "\nValor padrao do volume da caixa é: " << boxVolume(10,5,2)
    << endl;
    




    return 0;
}

inline int boxVolume(int length, int width, int heigth){

    return length * width * heigth;
}