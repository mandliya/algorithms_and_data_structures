// https : // practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1#

class Solution
{
public:
    int longestPalinSubseq(string A)
    {
        int n = A.size();
        string str = A;
        reverse(str.begin(), str.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (A[i - 1] == str[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};