/**
 * Problem: Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * Approach :
 * Step 1 :Iterate through array and :
 * 			- Ignore non positive numbers.
 *			- For a positive number, if we have A[i] = 'x', then in a sorted array in  original scheme of things,
 *			  it should be placed at A[x-1] ( since array is 0 indexed), so we swap A[i] with A[x-1].
 * Step 2: Iterate through array and now compare each value with their index, i.e. num[i] == i + 1.
 * 			- Whereever this check fails, that is the number at that index is missing, ( i.e. if A[i] is at wrong place, means i+1 is missing).
 */

#include <iostream>
#include <vector>



int firstMissingPositive(std::vector<int>& nums) {
	if( nums.size() == 0 ) {
		return 1;
	}
	size_t i = 0;
	for ( i = 0; i  < nums.size(); ++i) {
		while(nums[i] > 0 && nums[i] < int(nums.size()) && nums[i] != int(i+1) && nums[i] != nums[nums[i] - 1]) {
			std::swap(nums[i], nums[nums[i]-1]);
		}
	}
	i = 0;
	while( i < nums.size() && nums[i] == int(i + 1)) {
		++i;
	}
	return int(i+1);
}

void printVec(std::vector<int>& nums) {
	for ( auto num : nums ) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec1{ 1, 2, 0 };
	std::cout << "Vector:";
	printVec(vec1);
	std::cout << "First missing positive num :" << firstMissingPositive(vec1) << std::endl;

	std::vector<int> vec2{ 1000, -1 };
	std::cout << "Vector:";
	printVec(vec2);
	std::cout << "First missing positive num :" << firstMissingPositive(vec2) << std::endl;

	std::vector<int> vec3{ 3,4,-1,1 };
	std::cout << "Vector:";
	printVec(vec3);
	std::cout << "First missing positive num :" << firstMissingPositive(vec3) << std::endl;

	std::vector<int> vec4{ 0 };
	std::cout << "Vector:";
	printVec(vec4);
	std::cout << "First missing positive num :" << firstMissingPositive(vec4) << std::endl;

	std::vector<int> vec5{ 1 };
	std::cout << "Vector:";
	printVec(vec5);
	std::cout << "First missing positive num :" << firstMissingPositive(vec5) << std::endl;
	return 0;
}
