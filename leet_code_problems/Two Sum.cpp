// https : // leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (m.find(x) != m.end())
            {
                result.push_back(m[x]);
                result.push_back(i);
            }
            m[nums[i]] = i;
        }
        return result;
    }
};