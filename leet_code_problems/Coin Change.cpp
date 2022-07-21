// https : // leetcode.com/problems/coin-change/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = INT_MAX - 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }

        if (dp[n][amount] > amount)
            return -1;

        return dp[n][amount];
    }
};