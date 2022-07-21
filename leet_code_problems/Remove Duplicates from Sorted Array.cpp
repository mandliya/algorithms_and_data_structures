// https: // leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i;

        if (n == 0)
        {
            i = 0;
        }
        else
        {
            i = 1;
        }

        for (int j = 1; j < n; j++)
        {
            if (nums[j] > nums[j - 1])
            {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};