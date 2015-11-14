/*
 * Find the first repeating element in an array of integers
 * Given an array of integers, find the first repeating element in it.
 * We need to find the element that occurs more than once and whose index of first occurrence is smallest.
 * Examples:
 *
 * Input:  arr[] = {10, 5, 3, 4, 3, 5, 6}
 * Output: 5 [5 is the first element that repeats]
 *
 * Input:  arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
 * Output: 6 [6 is the first element that repeats]
 */


#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

int firstRepeating(std::vector<int> & arr) {
	std::unordered_set<int> arrSet;
	int min = -1;
	int arrSize = (int) arr.size();
	for ( int i = arrSize -1; i >= 0; i--) {
		if ( arrSet.find(arr[i]) != arrSet.end()) {
			min = i;
		} else {
			arrSet.insert(arr[i]);
		}
	}
	if ( min != -1 ) {
		return arr[min];
	} else {
		return std::numeric_limits<int>::min();
	}
}


void printArray( std::vector<int> & arr ) {
	std::cout << "Array :";
	for (auto a : arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::vector<int> arr{6, 10, 5, 4, 9, 120, 4, 6, 10};
	printArray(arr);
	std::cout << "First repeating element in above array is:" << firstRepeating(arr) << std::endl;

	std::vector<int> arr2 {10, 5, 3, 4, 3, 5, 6};
	printArray(arr2);
	std::cout << "First repeating element in above array is:" << firstRepeating(arr2) << std::endl;
	return 0;
}
