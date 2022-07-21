// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int major_element = nums[0];
        int cnt = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == major_element)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    major_element = nums[i];
                    cnt = 1;
                }
            }
        }

        return major_element;
    }
};