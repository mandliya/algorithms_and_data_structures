// https: // leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int i = 0;
        int k = 0;
        int n = nums.size();

        while (i < n)
        {
            if (nums[i] == 0)
            {
                i++;
            }
            else
            {
                nums[k++] = nums[i++];
            }
        }

        while (k < n)
        {
            nums[k] = 0;
            k++;
        }
    }
};