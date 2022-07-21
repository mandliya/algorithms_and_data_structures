// https : // leetcode.com/problems/sqrtx/

class Solution
{
public:
    int mySqrt(int x)
    {

        long long int result = -1;
        int s = 0;
        int e = x;

        while (s <= e)
        {
            long long int mid = s + (e - s) / 2;
            long long int sqt = mid * mid;
            if (sqt == x)
            {
                result = mid;
                return result;
            }

            else if (sqt < x)
            {
                result = mid;
                s = mid + 1;
            }

            else
            {
                e = mid - 1;
            }
        }

        return result;
    }
};