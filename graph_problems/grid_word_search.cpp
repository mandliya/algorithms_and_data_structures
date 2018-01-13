/*
 * Search a given word in a 2D board containing letters. 
 * The word can be constructed by sequentially traversing adjacent 
 * horizontal or vertical cells. In a sequence to form word,
 * letter on same position can not be used more than once.
 * 
 * Example:
 * Input:
 * 
 * ['H' 'E' 'Y' 'A']
 * ['O' 'L' 'A' 'Y']
 * ['I' 'L' 'O' 'V']
 * 
 * Word: HELLO
 * Output: Yes/true
 * 
 * Word: YELL
 * Output: Yes/true
 * 
 * Word: LOVE
 * Output: No/false
 * 
 * Assumption: grid or word does not contain '$' char
 * 
 * Approach: We can use Depth First Search with backtracking to solve this.
 * We can search the grid to match the first letter of search word
 * in the grid, and then apply depth first search on the grid at that position.
 * Finding appropriate next characters in the search word at each depth while
 * searching sequentially in the four directions.
 * 
 * We need some way to mark a position in grid as already visited. I will use
 * '$' to mark the position as visited, and we will reset the letter at the
 * position back to original letter at the end of backtracking.
 * 
 */

#include <iostream>
#include <vector>
#include <iomanip>

bool depth_first_search(std::vector<std::vector<char>>& grid, const std::string& word,
    int r, int c, int index)
{
    if (index == word.size()) {
        return true;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        return false;
    }

    if (word[index] != grid[r][c]) {
        return false;
    }

    char cur = grid[r][c];
    grid[r][c] = '$';
    bool result = false;

    result = depth_first_search(grid, word, r - 1, c, index + 1) ||
        depth_first_search(grid, word, r + 1, c, index + 1) ||
        depth_first_search(grid, word, r, c - 1, index + 1) ||
        depth_first_search(grid, word, r, c + 1, index + 1);

    grid[r][c] = cur;
    return result;
}



bool grid_search(std::vector<std::vector<char>>& grid, const std::string& word)
{
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
           if (word[0] == grid[i][j]) {
               if (depth_first_search(grid, word, i, j, 0)) {
                   return true;
               }
           }
        }
    }
    return false;
}

void print_grid(const std::vector<std::vector<char>>& grid)
{
    for (auto vec : grid) {
        std::cout << "{ ";
        for (auto c : vec) {
            std::cout << c << " ";
        }
        std::cout << "}" << std::endl;
    }
}

int main()
{
    std::vector<std::vector<char>> grid{
        {'H', 'E', 'Y', 'A'},
        {'O', 'L', 'A', 'Y'},
        {'I', 'L', 'O', 'V'}
    };
    print_grid(grid);
    std::cout << std::boolalpha;
    std::cout << "Does word 'HELLO' exist in grid? ";
    bool result = grid_search(grid, "HELLO");
    std::cout << result << std::endl;

    std::cout << "Does word 'HELL' exist in grid? ";
    result = grid_search(grid, "HELL");
    std::cout << result << std::endl;

    std::cout << "Does word 'LOVE' exist in grid? ";
    result = grid_search(grid, "LOVE");
    std::cout << result << std::endl;

    std::vector<std::vector<char>> grid2 {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    print_grid(grid2);
    std::cout << "Does word 'SEE' exist in grid? ";
    result = grid_search(grid2, "SEE");
    std::cout << result << std::endl;

    std::cout << "Does word 'ABCCSE' exist in grid? ";
    result = grid_search(grid2, "ABCCSE");
    std::cout << result << std::endl;

    std::cout << "Does word 'ABDE' exist in grid? ";
    result = grid_search(grid2, "ABDE");
    std::cout << result << std::endl;

    return 0;
}
