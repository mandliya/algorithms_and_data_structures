/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Approach: start putting all non zero elements from at the start, We will fill in all non zero elements in order.
 */

#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {
	size_t j = 0;
	for ( size_t i = 0; i < nums.size(); ++i ) {
		if ( nums[i] != 0 ) {
			std::swap(nums[i], nums[j]);
			++j;
		}
	}
}

void printVec(std::vector<int> & vec) {
	std::cout << "Vec:";
	for( auto & v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> nums{ 0, 1, 0, 3, 12 };
	std::cout << "Before ";
	printVec(nums);
	moveZeroes(nums);
	std::cout << "After ";
	printVec(nums);
	return 0;
}
