/**
 * Find the closest pair from two sorted arrays
 * Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.
 * We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.
 * Input:  ar1[] = {1, 4, 5, 7};
 *         ar2[] = {10, 20, 30, 40};
 *         x = 32
 *         Output:  1 and 30
 *
 *         Input:  ar1[] = {1, 4, 5, 7};
 *         ar2[] = {10, 20, 30, 40};
 *         x = 50
 *         Output:  7 and 40
 */

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cmath>

std::pair<int,int> closestPair( std::vector<int> & vec1, std::vector<int> & vec2, int x ) {
	int left = 0;
	int right = vec2.size() - 1;
	int minDiff = std::numeric_limits<int>::max();
	int leftRes, rightRes;
	while (left < vec1.size() && right >= 0 ) {
		int diff = std::abs(vec1[left] + vec2[right] - x);
		if ( diff < minDiff ) {
			minDiff = diff;
			leftRes = left;
			rightRes = right;
		}
		if ( vec1[left] + vec2[right] > x ) {
			--right;
		} else {
			++left;
		}
	}
	return std::make_pair(vec1[leftRes], vec2[rightRes]);
}

void printVec( std::vector<int> & vec ) {
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1  {1, 4, 5, 7};
	std::vector<int> vec2 {10, 20, 30, 40};
	std::cout << "Vec1: ";
	printVec(vec1);
	std::cout << "Vec2: ";
	printVec(vec2);
	int x = 32;
	std::cout << "x : " << x << std::endl;
	std::pair<int,int> result = closestPair(vec1, vec2, x);
	std::cout << "The closest pair from the above two sorted vectors to " << x << " is "
			  << "(" << result.first << ", " << result.second << ")" << std::endl;

	std::vector<int> vec3 {1, 4, 5, 7};
	std::vector<int> vec4 {10, 20, 30, 40};
	std::cout << "Vec3: ";
	printVec(vec3);
	std::cout << "Vec4: ";
	printVec(vec4);
	x = 50;
	std::cout << "x : " << x << std::endl;
	std::pair<int,int> result2 = closestPair(vec3, vec4, x);
	std::cout << "The closest pair from the above two sorted vectors to " << x << " is "
			  << "(" << result2.first << ", " << result2.second << ")" << std::endl;
	return 0;
}
