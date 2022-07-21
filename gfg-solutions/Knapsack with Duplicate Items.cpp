// https : // practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1));

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
        }

        return dp[N][W];
    }
};