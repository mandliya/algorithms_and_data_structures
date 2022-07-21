// https : // leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        vector<pair<int, int>> indices;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    indices.push_back(make_pair(i, j));
                }
            }
        }

        for (auto it : indices)
        {
            int m = it.first;
            int n = it.second;

            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][n] = 0;
            }

            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[m][j] = 0;
            }
        }
    }
};