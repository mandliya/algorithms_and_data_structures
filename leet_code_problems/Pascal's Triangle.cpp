// https : // leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> levels;

        if (numRows == 0)
        {
            return levels;
        }

        for (int i = 1; i <= numRows; i++)
        {
            vector<int> level;

            for (int j = 0; j < i; j++)
            {
                if (j == 0 or j == i - 1)
                {
                    level.push_back(1);
                }
                else
                {
                    level.push_back(levels[i - 2][j] + levels[i - 2][j - 1]);
                }
            }

            levels.push_back(level);
        }

        return levels;
    }
};