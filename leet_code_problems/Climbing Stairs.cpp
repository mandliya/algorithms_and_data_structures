// https : // leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {

        int *dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int result = dp[n];
        delete[] dp;
        return result;
    }
};

// Approach 2
class Solution
{
public:
    int climbStairs(int n)
    {

        int k = 2;
        int *dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int ans = 0;

            for (int j = 1; j <= k; j++)
            {
                if ((i - j) >= 0)
                {
                    ans += dp[i - j];
                }
            }

            dp[i] = ans;
        }

        return dp[n];
    }
};