// https : // practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#

class Solution
{
public:
    int countWays(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
            dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;

        return dp[n] % 1000000007;
    }
};