// https : // leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution
{
public:
    int numberOfSteps(int num)
    {

        int steps = 0;

        while (num)
        {
            if (num % 2 != 0)
            {
                num -= 1;
            }
            else
            {
                num /= 2;
            }

            steps++;
        }

        return steps;
    }
};