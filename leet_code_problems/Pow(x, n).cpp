// https : // leetcode.com/problems/powx-n/

class Solution
{
public:
    double solve(double x, int n)
    {
        // Base Case
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }

        // Recursive Call
        double ans = solve(x, n / 2);

        // Even
        if (n % 2 == 0)
        {
            return ans * ans;
        }
        // Odd
        else
        {
            return x * ans * ans;
        }
    }

    double myPow(double x, int n)
    {

        if (n < 0)
        {
            return 1 / solve(x, n);
        }
        else
        {
            return solve(x, n);
        }
    }
};