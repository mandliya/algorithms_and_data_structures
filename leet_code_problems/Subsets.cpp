// https : // leetcode.com/problems/subsets/

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int idx, int n)
    {
        if (idx == n)
        {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        solve(ans, tmp, nums, idx + 1, n);
        tmp.pop_back();
        solve(ans, tmp, nums, idx + 1, n);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;

        solve(ans, tmp, nums, 0, n);

        return ans;
    }
};