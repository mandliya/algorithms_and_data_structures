class Solution {
public:
    int minNumberOfOperations(string &a, string &b, int m, int n)
    {
        int dp[m+1][n+1];
        for (int i=0;i<=m;i++) dp[i][0] = i;
        for (int i=0;i<=n;i++) dp[0][i] = i;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        return minNumberOfOperations(word1, word2, word1.size(), word2.size());    
    }
};
