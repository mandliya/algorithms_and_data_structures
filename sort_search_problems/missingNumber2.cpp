/**
 * Find the missing number in Arithmetic Progression
 * Examples:
 * Input: arr[]  = {2, 4, 8, 10, 12, 14}
 * Output: 6
 *
 * Input: arr[]  = {1, 6, 11, 16, 21, 31};
 * Output: 26
 */

#include <iostream>
#include <vector>
#include <limits>

int findMissingUtil( std::vector<int> & vec, int diff) {
	size_t low = 0;
	size_t high = vec.size() - 1;
	while ( low < high ) {
		size_t mid = ( low + high ) / 2;

		//check if the missing element just after mid index is missing.
		if ( mid < vec.size() - 1 && vec[mid + 1] - vec[mid] != diff ) {
			return vec[mid] + diff;
		}

		// the element just before mid is missing.
		if ( mid > 0 && vec[mid-1] - vec[mid] != diff ) {
			return vec[mid - 1]  + diff;
		}

		//the sub array before mid is following AP
		if ( vec[mid] == vec[0] + diff * mid ) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return std::numeric_limits<int>::max();
}

void printVec( std::vector<int> & vec ) {
	std::cout << "Vec: ";
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int missingNumber( std::vector<int> & vec ) {
	int diff = (vec[vec.size() - 1] - vec[0])/(vec.size());
	return findMissingUtil( vec, diff );
}

int main() {
	std::vector<int> vec{ 2, 4, 8, 10, 12, 14 };
	printVec(vec);
	std::cout << "Missing number in above arithmetic progression is : "
			  << missingNumber(vec) << std::endl;
	return 0;
}
