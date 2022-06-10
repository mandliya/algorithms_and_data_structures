// https : // leetcode.com/problems/add-digits/

class Solution
{
public:
    int addDigits(int num)
    {

        if (num == 0)
        {
            return 0;
        }
        else if (num % 9 == 0)
        {
            return 9;
        }

        return num % 9;
    }
};