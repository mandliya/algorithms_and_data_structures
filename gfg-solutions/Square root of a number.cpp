// https : // practice.geeksforgeeks.org/problems/square-root/0/#

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        int s = 0;
        int e = x;

        long long int ans = -1;

        while (s <= e)
        {
            long long int mid = s + (e - s) / 2;
            long long sqt = mid * mid;

            if (sqt == x)
            {
                ans = mid;
                return ans;
            }
            else if (sqt < x)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }
};