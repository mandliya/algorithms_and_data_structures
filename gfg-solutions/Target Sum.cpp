// https : // practice.geeksforgeeks.org/problems/target-sum-1626326450/1#

class Solution
{
public:
    int findTargetSumWays(vector<int> &A, int target)
    {
        int sum = 0;
        int n = A.size();
        target = abs(target);

        for (auto i : A)
            sum += i;

        if ((sum + target) % 2 != 0 or target > sum)
            return 0;

        int s1 = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < s1 + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < s1 + 1; j++)
            {
                if (A[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i - 1]];
            }
        }

        return dp[n][s1];
    }
};