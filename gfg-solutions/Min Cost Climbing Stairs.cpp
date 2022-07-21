// https : // practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1#

class Solution
{
public:
    int helper(vector<int> cost, int N, vector<int> &dp)
    {
        if (N == 0 or N == 1)
            return cost[N];
        if (dp[N] != -1)
            return dp[N];
        return dp[N] = cost[N] + min(helper(cost, N - 1, dp), helper(cost, N - 2, dp));
    }

    int minCostClimbingStairs(vector<int> &cost, int N)
    {
        vector<int> dp(N + 1, -1);
        return min(helper(cost, N - 1, dp), helper(cost, N - 2, dp));
    }
};