/**
 * Given a sorted array of numbers, determine if there exists a fixed point, if so return index, or return -1. Fixed point in array is when i = arr[i].
 */

#include<iostream>
#include<vector>

int binarySearchFixedPoint( const std::vector<int> & arr) {
	int high = arr.size() -1;
	int low = 0;
	while ( low <= high ) {
		int mid = (low + high)/2;
		if ( arr[mid] == mid ) {
			return mid;
		} else if ( mid > arr[mid] ) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

void printVec( std::vector<int> & vec ) {
	std::cout << "VEC:";
	for ( auto & v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
	printVec(vec);
	int fixedPoint = binarySearchFixedPoint(vec);
	if (fixedPoint != -1) {
		std::cout << "Above vector has a fixed point at index(0 indexed): " << fixedPoint << std::endl;
	} else {
		std::cout << "Above vector has no fixed point\n";
	}
	return 0;
}
