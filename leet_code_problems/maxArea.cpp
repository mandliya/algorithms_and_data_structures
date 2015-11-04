/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */

#include <iostream>
#include <vector>
#include <limits>

int maxArea(std::vector<int>& height) {
	size_t l = 0;
	size_t r = height.size() - 1;
	int maxAr = std::numeric_limits<int>::min();
	while( l < r ) {
		int curAr = ( std::min(height[l], height[r]) * ( r - l ));
		if ( curAr > maxAr ) {
			maxAr = curAr;
		}
		if ( height[l] < height[r]) {
			l++;
		} else {
			r--;
		}
	}
	return maxAr;
}

void printVec( std::vector<int> & vec ) {
	std::cout << "Heights:";
	for( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> heights{ 4, 5, 1 };
	printVec(heights);
	std::cout << "Max possible area with above heights:" << maxArea(heights) << std::endl;
	return 0;
}
