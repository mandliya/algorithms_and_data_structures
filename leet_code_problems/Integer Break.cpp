// https : // leetcode.com/problems/integer-break/

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2 or n == 3)
            return n - 1;

        vector<int> prices(n);
        vector<int> length(n);

        for (int i = 0; i < n; i++)
            prices[i] = length[i] = i + 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (length[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(prices[i - 1] * dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
        }

        return dp[n][n];
    }
};