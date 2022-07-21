// https : // leetcode.com/problems/min-cost-climbing-stairs/

// Recursion
class Solution
{
public:
    int helper(vector<int> cost, int idx)
    {
        if (idx >= cost.size())
            return 0;
        return cost[idx] + min(helper(cost, idx + 1), helper(cost, idx + 2));
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(helper(cost, 0), helper(cost, 1));
    }
};

// Memoization
class Solution
{
public:
    int helper(vector<int> cost, int n, vector<int> &dp)
    {
        if (n == 0 or n == 1)
            return cost[n];
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = cost[n] + min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
    }
};

// DP
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[n - 1], dp[n - 2]);
    }
};