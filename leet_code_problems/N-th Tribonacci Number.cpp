// https : // leetcode.com/problems/n-th-tribonacci-number/

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 0 or n == 1 or n == 2)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for (int i = 3; i < n + 1; i++)
            dp[i] = dp[i - 3] + dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};