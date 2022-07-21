// https : // practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/0/#

int minDeletions(string str, int n)
{
    string str1 = str;
    reverse(str1.begin(), str1.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == str1[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n - dp[n][n];
}