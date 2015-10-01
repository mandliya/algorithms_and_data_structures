/*
 *  A simple divide and conquer approach to calculate pow(x,y)
 */

#include <iostream>


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
	std::cout << "Program to calculate power y to the base x\n";
	double x;
	int y;
	std::cout << "Enter base : ";
	std::cin >> x;
	std::cout << "Enter power(int + or -) : ";
	std::cin >> y;
	std::cout << "Power " << y << " to the base " << x << " is: ";
	std::cout <<  pow(x, y) << std::endl;
	return 0;
}
