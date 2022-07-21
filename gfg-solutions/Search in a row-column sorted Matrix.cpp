// https : // practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/#

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        int i = 0, j = m - 1;
        while (i < n and j >= 0)
        {
            if (matrix[i][j] == x)
                return true;
            else if (matrix[i][j] > x)
                j--;
            else
                i++;
        }

        return false;
    }
};