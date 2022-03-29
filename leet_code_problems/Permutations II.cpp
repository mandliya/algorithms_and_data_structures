// https : // leetcode.com/problems/permutations-ii/

class Solution
{
public:
    void findPermutations(vector<vector<int>> &ans, vector<int> &nums, int n, int idx)
    {
        if (idx == n)
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;

        for (int i = idx; i < n; i++)
        {
            if (s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
                swap(nums[i], nums[idx]);
                findPermutations(ans, nums, n, idx + 1);
                swap(nums[i], nums[idx]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int n = nums.size();
        int idx = 0;

        findPermutations(ans, nums, n, idx);

        return ans;
    }
};