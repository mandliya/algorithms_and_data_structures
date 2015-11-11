/**
 * Given an array A of n elements, find three indices i, j and k such that A[i]^2 + A[j]^2 = A[K]^2
 * O(n2) time complexity and O(1) space complexity
 */

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> squareSum( std::vector<int> & arr ) {
	std::vector<int> indices{ -1, -1, -1 };
	if ( arr.size() < 3 ) {
		return indices;
	}
	std::sort(arr.begin(), arr.end());

	for ( size_t i = 0; i < arr.size(); ++i ) {
		arr[i] = arr[i] * arr[i];
	}

	for ( size_t k = arr.size()-1; k >= 2; k-- ) {
		size_t i = 0;
		size_t j = k-1;
		while ( i < j ) {
			if ( arr[i] + arr[j] == arr[k] ) {
				indices[0] = i;
				indices[1] = j;
				indices[2] = k;
				return indices;
			}
			if ( arr[i] + arr[j] < arr[k] ) {
				i++;
			} else {
				j--;
			}
		}
	}
	return indices;
}

void printVec( std::vector<int> & vec ) {
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
	std::cout << "Vec:";
	printVec( vec );
	std::cout << "Indices i,j and k in above vector which forms A[i]^2 + A[j]^2 = A[k]^2 : ";
	std::vector<int> indices = squareSum(vec);
	printVec(indices);
	return 0;
}
