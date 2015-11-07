/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Can we do it in O(1) space complexity?
 */

#include <iostream>
#include <vector>
#include <utility>

int minPathSum(std::vector<std::vector<int>>& grid) {
	size_t m = grid.size();
	size_t n = grid[0].size();
	for ( size_t i = 1; i < m; ++i ) {
		grid[i][0] += grid[i-1][0];
	}
	for ( size_t i = 1; i < n; ++i ) {
		grid[0][i] += grid[0][i-1];
	}

	for ( size_t i = 1; i < m; ++i ) {
		for ( size_t j = 1; j < n; ++j ) {
			grid[i][j] += std::min( grid[i-1][j], grid[i][j-1]);
		}
	}
	return grid[m-1][n-1];
}

int main() {
	std::vector<std::vector<int>> grid {
									{ 1, 0, 5 },
									{ 2, 3, 1},
									{ 4, 1, 9}
								  };
	for ( size_t i = 0; i < grid.size(); ++i ) {
		for ( size_t j = 0; j < grid[0].size(); ++j ) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Min cost for above grid from moving top left to bottom right is "
			  <<  minPathSum(grid) << std::endl;
	return 0;
}
