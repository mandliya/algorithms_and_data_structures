// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

class Solution
{
public:
    int helper(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp = helper(arr, i, k, dp) + helper(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            mn = min(temp, mn);
        }
        return dp[i][j] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return helper(arr, 1, N - 1, dp);
    }
};