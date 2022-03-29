// https : // leetcode.com/problems/longest-common-subsequence/

// Recursive
class Solution
{
public:
    int maxSubq(string str1, int i, string str2, int j)
    {
        if (i == str1.size() or j == str2.size())
        {
            return 0;
        }

        if (str1[i] == str2[j])
        {
            return 1 + maxSubq(str1, i + 1, str2, j + 1);
        }

        return max(maxSubq(str1, i, str2, j + 1), maxSubq(str1, i + 1, str2, j));
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        return maxSubq(text1, 0, text2, 0);
    }
};

// Dynamic Programming
class Solution
{
public:
    int longestCommonSubsequence(string str1, string str2)
    {

        int m = str1.size();
        int n = str2.size();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int result = dp[m][n];
        return result;
    }
};