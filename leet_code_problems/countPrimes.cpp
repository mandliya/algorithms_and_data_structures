/**
 * Count the number of prime numbers less than a non-negative number, n.
 */

#include <iostream>
#include <vector>
#include <cmath>



int countPrimes(int n) {
	if ( n <= 2) {
		return 0;
	}
	int x = std::sqrt(n);
	std::vector<bool> soe(n, false);
	soe[1] = true;
	for ( int i = 2; i <= x ; ++i ) {
		if (soe[i] == false ) {
			for (int j = i * i; j < n; j+=i) {
				soe[j] = true;
			}
		}
	}
	int count = 0;
	for ( int i = 2; i < n; ++i ) {
		if(soe[i] == false) {
			++count;
		}
	}
	return count;
}


int main() {
	std::cout << "Enter a non negative integer:" ;
	int n;
	std::cin >> n;
	std::cout << "Number of primes less than " << n << "  are " << countPrimes(n) << std::endl;
	return 0;
}
