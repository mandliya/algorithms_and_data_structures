/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */


#include <iostream>
#include <vector>
#include <algorithm>


int threeSumClosest(std::vector<int>& nums, int target) {
	int closestSum = (nums[0] + nums[1] + nums[2]);
	std::sort(nums.begin(), nums.end());
	for ( size_t i = 0 ;i < nums.size() - 2; ++i ) {
		size_t k = nums.size() - 1;
		size_t j = i + 1;
		while( j < k )  {
			int currSum = (nums[i] + nums[j] + nums[k]);
			if ( currSum == target ) {
				return currSum;
			}
			if ( abs(target - closestSum) > abs(target - currSum)) {
				closestSum = currSum;
			}
			if ( currSum > target ) {
				--k;
			} else {
				++j;
			}
		}
	}
	return closestSum;
}

int main() {
	std::vector<int> vec{ -1,2,1,-4 };
	std::cout << "Vec:";
	for ( auto c : vec ) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	std::cout << "Three sum closest to 1 in above vector is :" << threeSumClosest(vec, 1) << std::endl;
	return 0;
}
