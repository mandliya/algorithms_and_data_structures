// https : // leetcode.com/submissions/detail/664144063/

class Solution
{
public:
    bool isPowerOfThree(int n)
    {

        if (n == 0)
        {
            return false;
        }

        if (n == 1)
        {
            return true;
        }

        if (n % 3 == 0)
        {
            return isPowerOfThree(n / 3);
        }

        return false;
    }
};