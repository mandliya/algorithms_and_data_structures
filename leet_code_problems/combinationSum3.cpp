/**
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used
 * and each combination should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 * Example:
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 * [[1,2,4]]
 *
 * Input: k = 3, n = 9
 *
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>


void combination( std::vector<std::vector<int>> & results, std::vector<int> & curr, int k, int n, int idx ) {
	if ( k == 0 && n == 0 ) {
		results.push_back(curr);
		return;
	}

	for ( int i = idx; i <= 10 - k && i <= n; ++i ) {
		curr.push_back(i);
		combination(results, curr, k - 1, n - i, i + 1 );
		curr.pop_back();
	}

}


std::vector<std::vector<int>> combinationVec( int k, int n ) {
	std::vector<std::vector<int>> results;
	std::vector<int> curr;
	combination(results, curr, k, n, 1);
	return results;
}

void printVecVec( std::vector<std::vector<int>> & vec ) {
	for ( auto v : vec ) {
		std::cout << "[ ";
		for ( auto e : v ) {
			std::cout << e << " ";
		}
		std::cout << "]" << std::endl;
	}
}


int main() {
	std::vector<std::vector<int>> results;
	std::cout << "Combinations for k = 3, n = 7\n";
	results = combinationVec(3,7);
	printVecVec(results);
	results.clear();
	std::cout << "\nCombinations for k = 3, n = 9\n";
	results = combinationVec(3,9);
	printVecVec(results);
	return 0;
}


