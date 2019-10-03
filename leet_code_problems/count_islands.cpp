/*
 * In a given 2D grid, 1 represents land and 0 represents water body.
 * We need to count number of islands.
 * An island is surrounded by connecting neighbouring lands vertically
 * or horizontally.
 * Assume: That everything around the grid is water.
 * 
 * Approach: We can solve this problem with Depth/Breadth first search.
 * 
 * With Depth first search:
 * Consider a land body, and start a depth first search, and mark all the
 * connected land bodies to it as water bodies (i.e. mark all connected 1's 
 * as 0 to mark them visited)
 * In this case, number of islands for which DFS was started is the total
 * count of islands.
 * Similar idea could be used for BFS.
 * 
 * Example:
 * 
 * 1 1 0 0
 * 1 0 1 0
 * 1 0 0 1
 * 
 * There are 3 islands in above grid.
 */

#include <iostream>
#include <vector>

void depth_first_search(std::vector<std::vector<int> >& grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }
    grid[i][j] = 0;
    if (i + 1 < m && grid[i + 1][j] == 1) {
        depth_first_search(grid, i + 1, j);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        depth_first_search(grid, i - 1, j);
    }
    if (j + 1 < n &&  grid[i][j + 1] == 1) {
        depth_first_search(grid, i, j + 1);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
        depth_first_search(grid, i, j - 1);
    }
}

int number_of_islands(std::vector<std::vector<int>>& grid)
{
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();
    int total_islands = 0;
    for ( int i = 0; i < m; ++i) {
        for ( int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++total_islands;
                depth_first_search(grid, i, j);
            }
        }
    }
    return total_islands;
}


int main()
{
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Total number of islands in the grid is :"
    << number_of_islands(grid) << std::endl;
    return 0;
}