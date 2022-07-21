// https : // practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += arr[i];

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            }
        }

        int min_diff = INT_MAX;

        for (int j = sum / 2; j >= 0; j--)
        {
            if (dp[n][j] == true)
                min_diff = min(min_diff, sum - 2 * j);
        }

        return min_diff;
    }
};
