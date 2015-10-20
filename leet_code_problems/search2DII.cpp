/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 */

#include <iostream>
#include <vector>

bool searchMatrix( std::vector<std::vector<int>> matrix, int target ) {
	int M = matrix.size();
	int N = matrix[0].size();
	if ( target < matrix[0][0] || target > matrix[M-1][N-1] ) {
		return false;
	}

	int row = 0;
	int col = N - 1;
	while ( row <= M -1 && col >= 0 ) {
		if ( matrix[row][col] == target ) {
			return true;
		} else if ( matrix[row][col] > target ) {
			col--;
		} else {
			row++;
		}
	}
	return false;
}

int main() {
  std::vector<std::vector<int>> matrix = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  std::cout << searchMatrix(matrix, 5) << std::endl;
  std::cout << searchMatrix(matrix, 20) << std::endl;
  return 0;
}

