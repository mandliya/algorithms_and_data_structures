// https : // leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                cnt1++;
            }
            else if (nums[i] == 1)
            {
                cnt2++;
            }
            else if (nums[i] == 2)
            {
                cnt3++;
            }
        }

        int j = 0;

        while (cnt1 != 0)
        {
            nums[j] = 0;
            cnt1--;
            j++;
        }

        while (cnt2 != 0)
        {
            nums[j] = 1;
            cnt2--;
            j++;
        }
        while (cnt3 != 0)
        {
            nums[j] = 2;
            cnt3--;
            j++;
        }
    }
};