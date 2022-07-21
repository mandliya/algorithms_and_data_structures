// https : // leetcode.com/problems/broken-calculator/

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {

        int cnt = 0;

        while (startValue < target)
        {
            if (target % 2)
            {
                target++;
            }
            else
            {
                target /= 2;
            }

            cnt++;
        }

        return cnt + startValue - target;
    }
};