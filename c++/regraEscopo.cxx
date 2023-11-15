#include <iostream>
using std::cout;
using std::endl;

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x{1};

int main(){

    int x = 5;

    cout << "local x fora escopo é: "<< x << endl;

    {
        int x = 7;
    
        cout << "Local scopo x: " << x << endl; 
    }
    
    cout << "Local x fora do escopo dentro do main: " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    cout << "x dentro de main fora do escopo: " << x << endl;

    return 0;
}

void useLocal(void){
    int x{25};

    cout << "Local useLocal x eh: " << x << endl;
    x++;
    cout << "x++ dentro de useLocal: " << x << endl;
}

void useStaticLocal(void){

    static int x{50};

    cout << "\nLocal useStaticLocal x: " << x << endl;
    x++;

    cout << "x++ dentro de useStaticLocal: " << x << endl;
    
}

void useGlobal(void){

    cout << "\nuseGlobal x: " << x << endl;
    x *=10;
    cout << "useGlobal x *= 10: " << x << endl;

}