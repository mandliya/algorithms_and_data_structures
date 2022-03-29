// https : // leetcode.com/problems/n-queens/

// BRUTE FORCE
class Solution
{
public:
    bool isPossible(int col, int row, vector<string> &chess, int n)
    {
        int tmp_row = row;
        int tmp_col = col;

        while (col >= 0 and row >= 0)
        {
            if (chess[row][col] == 'Q')
            {
                return false;
            }

            row--;
            col--;
        }

        row = tmp_row;
        col = tmp_col;

        while (col >= 0)
        {
            if (chess[row][col] == 'Q')
            {
                return false;
            }

            col--;
        }

        row = tmp_row;
        col = tmp_col;

        while (row < n and col >= 0)
        {
            if (chess[row][col] == 'Q')
            {
                return false;
            }

            row++;
            col--;
        }

        return true;
    }

    void solver(vector<string> &chess, vector<vector<string>> &ans, int col, int n)
    {
        if (n == col)
        {
            ans.push_back(chess);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isPossible(col, row, chess, n))
            {
                chess[row][col] = 'Q';
                solver(chess, ans, col + 1, n);
                chess[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;

        int col = 0;
        string str(n, '.');

        vector<string> chess(n, str);

        solver(chess, ans, col, n);

        return ans;
    }
};