/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 * Approach : Here we have to observe that array value represents *maximum* value, so we can always jump j index from index i as long as j < A[i].
 * i.e. if A[i] = 3, we can jump either 1, 2, or 3 steps.
 * Now, We will use dynamic programing to solve this problem. Our subproblem is at any index i, what is the farthest index I can jump. If in the end
 * if the max value index we have gathered so far is bigger than array length, we have reached the last index.
 */

#include <iostream>
#include <vector>

bool canReach( std::vector<int> & vec ) {
	int n = vec.size();
	if ( n == 0 ) {
		return false;
	}
	if ( n == 1 ) {
		return true;
	}
	int m = 0;
	for (int i = 0; i < n; ++i ) {
		if ( i <= m ) {
			m = std::max( m, vec[i] + i );
			if ( m >= n-1) {
				return true;
			}
		}
	}
	return false;
}

void printRes( std::vector<int> & vec ) {
	std::cout << "VEC:";
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	std::cout << (canReach(vec) ? "True" : "False");
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1{ 2,3,1,1,4 };
	std::vector<int> vec2{ 3,2,1,0,4 };
	printRes(vec1);
	printRes(vec2);
	return 0;
}
