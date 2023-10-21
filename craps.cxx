#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

int rollDice();

int main(){
    enum Status{ CONTINUE, WON, LOST };

    int myPoint;
    Status gameStatus;

    srand( time(0));

    int sumeOfDice = rollDice();

    switch( sumeOfDice){
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumeOfDice;
            cout << "Point is " << myPoint << endl;
            break;
    }

    while( gameStatus == CONTINUE){
        sumeOfDice = rollDice();

        if( sumeOfDice == myPoint)
            gameStatus = WON;
        else
            if( sumeOfDice == 7)
                gameStatus = LOST;
    }

    if( gameStatus == WON )
        cout << "Player wins" << endl;
    else
        cout << "Player loses" << endl;
    cout << Status(gameStatus) << endl;
    return 0;
}

int rollDice(){
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    int sum = die1 + die2;

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

    return sum;
}
