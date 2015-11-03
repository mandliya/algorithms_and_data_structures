/**
 * An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.
 * Example:
 * vec : { 1, 60, -10, 70, -80, 85 }
 *
 * output: -80, 85
 *
 * If no such pair exists return a { 0, 0 } pair
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::pair<int, int> pairSumClosestToZero( std::vector<int> & vec ) {
	std::pair<int, int> minPair( 0, 0 );
	if ( vec.size() < 2 ) {
		return minPair;
	}

	size_t minLeft = 0, minRight = vec.size()-1;
	size_t left = 0, right = vec.size() -1;
	int minSum = std::numeric_limits<int>::max();

	std::sort( vec.begin(), vec.end() );

	while( left < right ) {
		int sum = vec[left] + vec[right];
		if ( std::abs(minSum) > std::abs(sum) ) {
			minSum = sum;
			minLeft = left;
			minRight = right;
		}
		if ( sum > 0 ) {
			--right;
		} else {
			++left;
		}
	}
	minPair.first = vec[minLeft];
	minPair.second = vec[minRight];
	return minPair;
}


int main() {
	std::vector<int> vec{  1, 60, -10, 70, -80, 85 };
	std::cout << "Vec: ";
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::pair<int, int> minPair = pairSumClosestToZero(vec);
	std::cout << "Pair whose sum is closes to 0 in above vector is: ("
			  << minPair.first << ", " << minPair.second << ")" << std::endl;
	return 0;
}
