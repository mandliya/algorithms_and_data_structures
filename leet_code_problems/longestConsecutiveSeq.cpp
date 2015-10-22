/**
 * Leet code problem:
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 */


#include <iostream>
#include <vector>
#include <unordered_map>

int longestConsecutive(std::vector<int>& nums) {
	std::unordered_map<int,int> hashMap;
	for ( auto n : nums ) {
		hashMap.insert({n, -1});
	}
	int max_so_far = 0;
	for ( size_t i = 0; i < nums.size(); ++i ) {
		int j = 0;
		int k = nums[i];
		while( hashMap.find(k + j) != hashMap.end() ) {
			if (hashMap[k+j] != -1 ) {
				j += hashMap[k+j];
				break;
			}
			++j;
		}
		hashMap[k] = j;
		if ( j > max_so_far ) {
			max_so_far = j;
		}
	}
	return max_so_far;
}

void printVec(std::vector<int> & vec) {
	for ( auto & v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
int main() {

	std::cout << "Vector:";
	std::vector<int> vec{ 100, 4, 200, 1, 3, 2 };
	printVec(vec);
	std::cout << "Longest consecutive sequence length:" << longestConsecutive(vec) << std::endl;
	return 0;
}
