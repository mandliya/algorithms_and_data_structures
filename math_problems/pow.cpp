/*
 *  A simple divide and conquer approach to calculate pow(x,y)
 */

#include <iostream>
using namespace std;

double pow( double x, int y )
{
	//base case
	if ( y == 0 ) {
		return 1;
	}
	double temp = pow(x, y/2);
	if ( y % 2 == 0 ) {
		return temp * temp;
	} else {
		if ( y > 0 ) {
			return x * temp * temp;
		} else {
			return ( temp * temp ) / x;
		}
	}
}

int main()
{
	cout << "Program to calculate power y to the base x\n";
	double x;
	int y;
	cout << "Enter base : ";
	cin >> x;
	cout << "Enter power(int + or -) : ";
	cin >> y;
       cout << "Power " << y << " to the base " << x << " is: ";
	cout <<  pow(x, y) << endl;
	return 0;
}
