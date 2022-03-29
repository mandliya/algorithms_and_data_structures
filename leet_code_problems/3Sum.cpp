// https : // leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            int val = nums[i];

            while (j < k)
            {
                if (val + nums[j] + nums[k] == 0)
                {
                    s.insert({val, nums[j++], nums[k--]});
                }
                else if ((val + nums[j] + nums[k]) < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        for (auto i : s)
        {
            result.push_back(i);
        }
        return result;
    }
};