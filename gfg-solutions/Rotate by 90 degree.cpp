// https : // practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1#

class Solution
{
public:
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
