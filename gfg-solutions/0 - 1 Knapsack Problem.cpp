// https : // practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// Recursive

class Solution
{
public:
    int helper(int W, int wt[], int val[], int n)
    {
        if (W == 0 or n == -1)
        {
            return 0;
        }

        else if (wt[n] > W)
        {
            return helper(W, wt, val, n - 1);
        }

        else
        {
            return max(val[n] + helper(W - wt[n], wt, val, n - 1), helper(W, wt, val, n - 1));
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        return helper(W, wt, val, n - 1);
    }
};

// Memoization

class Solution
{
public:
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (n == 0 or W == 0)
        {
            return 0;
        }

        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        else if (W < wt[n - 1])
        {
            return dp[n][W] = helper(W, wt, val, n - 1, dp);
        }

        else
        {
            return dp[n][W] = max(val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1, dp), helper(W, wt, val, n - 1, dp));
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        int max_profit = helper(W, wt, val, n, dp);

        return max_profit;
    }
};

// DP

class Solution
{
public:
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (n == 0 or W == 0)
        {
            return 0;
        }

        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        else if (W < wt[n - 1])
        {
            return dp[n][W] = helper(W, wt, val, n - 1, dp);
        }

        else
        {
            return dp[n][W] = max(val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1, dp), helper(W, wt, val, n - 1, dp));
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        int max_profit = helper(W, wt, val, n, dp);

        return max_profit;
    }
};