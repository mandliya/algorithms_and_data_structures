// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < n && nums[i] == temp[i])
        {
            i++;
        }

        while (j >= 0 && nums[j] == temp[j])
        {
            j--;
        }
        if (i == n)
        {
            return 0;
        }

        return abs(j - i) + 1;
    }
};