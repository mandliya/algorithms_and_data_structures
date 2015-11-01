/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 */

#include <iostream>
#include <vector>

int missingNumber( std::vector<int>& nums ) {
	int missing_sum = 0;
	for ( auto n : nums ) {
		missing_sum += n;
	}
	int n = nums.size();
	int expected_sum = 0;
	if ( n % 2 == 0 ) {
		expected_sum = (n/2) * (n + 1);
	} else {
		expected_sum = n * ( (n+1)/2 );
	}
	return expected_sum - missing_sum;
}

void printVec( std::vector<int> & vec ) {
	std::cout << "Vec:";
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec{ 0, 1, 3 };
	printVec(vec);
	std::cout << "Missing number in above vector is :" << missingNumber(vec) << std::endl;
	return 0;
}
