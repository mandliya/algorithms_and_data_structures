/*
 * Level : Easy
 * Given a grid, calculate the maximum number of unique paths
 * from source (0,0) to destination (m, n). You can only move
 * either in down or in right direction.
 * 
 *  S . . . . . . . .
 *  . . . . . . . . .
 *  . . . . . . . . .
 *  . . . . . . . . .
 *  . . . . . . . . .
 *  . . . . . . . . D
 * 
 * In this 6 x 9 grid, 
 * unique paths from source origin to destination are 1287.
 * 
 */

#include <iostream>
#include <vector>

int unique_paths(int m, int n)
{
    std::vector<std::vector<int>> paths(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        paths[i][0] = 1;
    }

    for (int j = 0; j < n; ++j) {
        paths[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }
    }
    return paths[m-1][n-1];
}

int main()
{
    std::cout << "Number of unique paths for 6 x 9 grid: " <<
        unique_paths(6, 9) << std::endl;
    return 0;
}