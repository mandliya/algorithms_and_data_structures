/**
 * Find the maximum element in an array which is first increasing and then decreasing.
 * Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
 * Output: 500
 *
 * Also consider cases like
 * Input: arr[] = {10, 20, 30, 40, 50}
 * Output: 50
 *
 * Input: arr[] = {120, 100, 80, 20, 0}
 * Output: 120
 */

#include <iostream>
#include <vector>

int findMaximum(std::vector<int> & arr, int low, int high) {
	// subset has only one element
	if ( high == low ) {
		return arr[low];
	}

	//subset has 2 elements
	if ( high - low == 1 ) {
		return arr[high] > arr[low] ? arr[high] : arr[low];
	}

	int mid = ( high + low )/2;
	if ( arr[mid-1] > arr[mid] ) {
		return findMaximum(arr, low, mid-1);
	} else {
		return findMaximum(arr, mid+1, high);
	}

}

void printVec( std::vector<int> & arr ) {
	std::cout << "Arr:";
	for ( auto & a : arr ) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::vector<int> arr1{ 8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 };
	printVec(arr1);
	std::cout << "Max in above arr:" << findMaximum( arr1, 0, arr1.size()-1 ) << std::endl;

	std::vector<int> arr2{1, 3, 50, 10, 9, 7, 6};
	printVec(arr2);
	std::cout << "Max in above arr:" << findMaximum( arr2, 0, arr2.size()-1 ) << std::endl;


	std::vector<int> arr3{10, 20, 30, 40, 50};
	printVec(arr3);
	std::cout << "Max in above arr:" << findMaximum( arr3, 0, arr3.size()-1 ) << std::endl;

	std::vector<int> arr4{120, 100, 80, 20, 0};
	printVec(arr4);
	std::cout << "Max in above arr:" << findMaximum( arr4, 0, arr4.size()-1 ) << std::endl;

	return 0;
}
