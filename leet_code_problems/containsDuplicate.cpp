/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 *
 * Approach : sort and check for adjacent elements for duplicates.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>


bool containsDuplicate(std::vector<int>& nums) {
	std::sort( nums.begin(), nums.end());
	for ( size_t i = 1; i < nums.size(); ++i ) {
		if ( nums[i-1] == nums[i] ) {
			return true;
		}
	}
	return false;
}

void printVect( std::vector<int> & vec ) {
	std::cout << "VEC:";
	for ( auto & i : vec ) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1{ 1, 99, 99, 4, 8, 98, 96, 3, 5, 19, 23, 17, 84, 23 };
	printVect(vec1);
	if ( containsDuplicate(vec1) ) {
		std::cout << "Above vector contains duplicates\n";
	} else {
		std::cout << "Above vector does not contain duplicates\n";
	}
	return 0;
}
