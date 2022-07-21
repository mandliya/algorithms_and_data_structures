// https : // practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;

        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return false;

        sum /= 2;

        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1));

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[N][sum];
    }
};