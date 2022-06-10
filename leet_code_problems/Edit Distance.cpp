/*
// https : // leetcode.com/problems/edit-distance/

// Recursive
class Solution
{
public:
    int mD(string s1, int m, string s2, int n)
    {
        if (m == 0)
        {
            return n; /// insert all of s2
        }
        if (n == 0)
        {
            return m; /// del all of s1
        }

        if (s1[m - 1] == s2[n - 1])
        {
            return mD(s1, m - 1, s2, n - 1);
        }
        int insert = mD(s1, m, s2, n - 1);
        int del = mD(s1, m - 1, s2, n);
        int replace = mD(s1, m - 1, s2, n - 1);
        return 1 + min(insert, min(del, replace));
    }

    int minDistance(string word1, string word2)
    {
        return mD(word1, word1.size(), word2, word2.size());
    }
};
*/

// DP
class Solution
{
public:
    int minDistance(string s1, string s2)
    {

        int m = s1.size();
        int n = s2.size();

        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
            }
        }

        return dp[m][n];
    }
};