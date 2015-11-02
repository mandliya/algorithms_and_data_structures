/**
 * Find Minimum in Rotated Sorted Array
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
	int n = nums.size();
	if ( n == 1 ) {
		return nums[0];
	}
	if ( n == 2 ) {
		return ( nums[0] < nums[1] ? nums[0] : nums[1]);
	}
	int i = n - 1;
	while ( i > 0 && nums[i] > nums[i-1]) {
		--i;
	}
	return nums[i];
}


int main() {
	std::cout << "Vec:";
	std::vector<int> vec{ 4, 5, 6, 7, 0, 1, 2 };
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	std::cout << "Min in above vector: " << findMin(vec) << std::endl;
	return 0;
}
