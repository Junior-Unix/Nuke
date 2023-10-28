#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void modifyArray( int [], int );
void modifyElement( int );

int main(){

	const int arraySize{ 5 };
	int a[ arraySize ]{ 0, 1, 2, 3, 4 };

	cout << "Effects of passing entire array by reference:"
		<< "\n\nThe values of the original array are:\n";

	for ( int i{ 0 }; i < arraySize; i++ )
		cout << setw( 3 ) << a[ i ];

	cout << endl;

	modifyArray( a, arraySize );
	cout << "The values of the modifie array are:\n";

	for ( int j{ 0 }; j < arraySize; j++ )
		cout << setw( 3 ) << a[ j ];

	cout << "\n\n\nEffects od passing array element by value:"
		<< "\n\na[ 3 ] before modifyElement: " << a[ 3 ] << endl;


	return 0;

}

void modifyArray( int b[], int sizeOfArray ){

	for ( int k{ 0 }; k < sizeOfArray; k++ )
		b[ k ] *= 2;

}

void modifyElement( int e ){

	cout << "Value of element in modifyElement: " << ( e *= 2 ) << endl;

}
