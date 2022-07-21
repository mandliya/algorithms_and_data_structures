// https : // practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int mx = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++)
                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

        for (auto i : dp)
            for (auto j : i)
                mx = max(mx, j);

        return mx;
    }
};