// https : // leetcode.com/problems/summary-ranges/

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();
        int i = 0;

        vector<string> result;

        while (i < n)
        {
            int s = i;
            int j = i + 1;

            while (j < n and nums[i] == nums[j] - 1)
            {
                i++;
                j++;
            }

            if (nums[s] == nums[i])
            {
                result.push_back(to_string(nums[s]));
            }
            else
            {
                result.push_back(to_string(nums[s]) + "->" + to_string(nums[i]));
            }

            i = j;
        }

        return result;
    }
};