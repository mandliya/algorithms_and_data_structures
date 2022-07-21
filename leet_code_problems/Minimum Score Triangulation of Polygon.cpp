// https : // leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution
{
public:
    int helper(vector<int> &values, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int min_so_far = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tmp = helper(values, i, k, dp) + helper(values, k + 1, j, dp) + (values[i - 1] * values[k] * values[j]);
            min_so_far = min(min_so_far, tmp);
        }

        return dp[i][j] = min_so_far;
    }

    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int>> dp(values.size() + 1, vector<int>(values.size() + 1, -1));
        return helper(values, 1, values.size() - 1, dp);
    }
};