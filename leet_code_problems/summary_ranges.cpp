/*
 * Leet code problem - summary pages
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ranges;
        if (nums.empty()) {
            return ranges;
        }
        std::string curr = std::to_string(nums[0]);
        int range_start = nums[0];

        for( size_t i = 1; i < nums.size(); ++i ) {
            if (nums[i-1] + 1 == nums[i]) {
                continue;
            } else {
                if ( range_start != nums[i-1]) {
                    curr += "->";
                    curr += std::to_string(nums[i-1]);
                    ranges.push_back(curr);
                } else {
                    ranges.push_back(curr);
                }
                curr = std::to_string(nums[i]);
                range_start = nums[i];
            }
        }
        if (range_start != nums[nums.size() - 1]) {
            curr += "->";
            curr += std::to_string(nums[nums.size() - 1]);
        }
        ranges.push_back(curr);
        return ranges;
}

void printVec( std::vector<std::string> ranges ) {
	for ( size_t i = 0; i < ranges.size(); ++i ) {
		if ( i != ranges.size() - 1 ) {
			std::cout << ranges[i] << ", ";
		} else {
			std::cout << ranges[i] << std::endl;
		}
	}
}

int main() {
	std::vector<int> nums{0,1,2,4,5,7};
	std::vector<std::string> ranges = summaryRanges(nums);
	printVec(ranges);
	return 0;
}
