/**
 * Calculating Fibonacci series term of index N using DP memoization.
 */

#include <iostream>
#include <vector>

//bottom up

int fib1(int n) {
	// space optimization
	std::vector<int> fib(3, 0);
	if ( n == 0 || n == 1 ) {
		return 1;
	}
	fib[0] = 1;
	fib[1] = 1;
	for ( int i = 2; i < n; ++i ) {
		fib[2] = fib[1] + fib[0];
		fib[0] = fib[1];
		fib[1] = fib[2];
	}
	return fib[1];
}

//top down

// Ignoring Space wastage
int fib2( int n , int * fib) {
	if ( n == 0 ) {
		return 0;
	}
	if ( n == 1 || n == 2 ) {
		return 1;
	}
	if ( fib[n] != 0 ) {
		return fib[n];
	}
	fib[n] = fib2(n-1) + fib2(n-2);
	return fib[n];
}

//leverage the fact we are just using last 2 term
// bottom up
int fib3( int n ) {
	int a = 0;
	int b = 1;
	for ( int i = 2; i <=  n; ++i ) {
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
}


int main()
{
	int n;
	std::cout << "\Enter n\t:\t";
	std::cin >> n;
	int * fib = new int[n];
	std::cout << "Demonstrating fibonacci term calculation:\n";
	std::cout << fib1(b) << " " << fib2(n , fib) << " " << fib3(n) << std::endl;
	return 0;
}
