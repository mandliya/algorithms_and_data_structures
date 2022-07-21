// https : // practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1#

class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        vector<long long int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }

        return dp[n];
    }
};