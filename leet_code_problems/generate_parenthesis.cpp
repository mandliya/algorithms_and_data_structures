/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */

#include <iostream>
#include <vector>
#include <string>


void generate_parenthesis_helper( int n, int left, int right, std::string curr, std::vector<std::string> & result ) {
	if (right == n) {
		result.push_back(curr);
	} else {
		if (left < n) {
			generate_parenthesis_helper( n, left + 1, right, curr + '(', result);
		}
		if (right < left) {
			generate_parenthesis_helper( n, left, right + 1, curr + ')', result);
		}
	}
}

std::vector<std::string> generate_parenthesis( int n ) {
	std::vector<std::string> result;
	std::string curr{ "" };
	generate_parenthesis_helper(n, 0, 0, curr, result);
	return result;
}

int main() {
	std::vector<std::string> result = generate_parenthesis(3);
	for ( auto s : result ) {
		std::cout << "{ " << s << " }" << std::endl;
	}
	return 0;
}
