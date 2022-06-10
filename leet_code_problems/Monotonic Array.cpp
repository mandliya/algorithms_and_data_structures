// https : // leetcode.com/problems/monotonic-array/

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {

        bool isDecreasing = false;
        bool isIncreasing = false;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
            {
                isIncreasing = true;
            }
            else if (nums[i - 1] > nums[i])
            {
                isDecreasing = true;
            }
        }

        return isDecreasing && isIncreasing ? false : true;
    }
};