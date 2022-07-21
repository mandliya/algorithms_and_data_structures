// https: // practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

class Solution
{
public:
    bool is_palindrome(string str, int i, int j)
    {
        while (i <= j)
        {
            if (str[i] != str[j])
                return false;
            i++, j--;
        }
        return true;
    }

    int helper(string str, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j or is_palindrome(str, i, j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int min_partitions = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int left, right;
            if (dp[i][k] != -1)
                left = dp[i][k];
            else
                left = helper(str, i, k, dp);
            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
                right = helper(str, k + 1, j, dp);
            int tmp = 1 + left + right;
            min_partitions = min(tmp, min_partitions);
        }
        return dp[i][j] = min_partitions;
    }

    int palindromicPartition(string str)
    {
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, -1));
        return helper(str, 0, str.size() - 1, dp);
    }
};