// https : // practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

class Solution
{

public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j] % 1000000007;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % 1000000007;
                }
            }
        }

        return dp[n][sum] % 1000000007;
    }
};