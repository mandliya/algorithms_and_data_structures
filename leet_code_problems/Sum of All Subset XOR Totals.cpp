// https : // leetcode.com/problems/sum-of-all-subset-xor-totals/

// Recursion
class Solution
{
public:
    void helper(vector<vector<int>> &ds, vector<int> &tmp, vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            ds.push_back(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        helper(ds, tmp, nums, idx + 1);
        tmp.pop_back();
        helper(ds, tmp, nums, idx + 1);
    }

    int subsetXORSum(vector<int> &nums)
    {
        vector<vector<int>> ds;
        vector<int> tmp;
        helper(ds, tmp, nums, 0);

        int total = 0;

        for (int i = 0; i < ds.size(); i++)
        {
            int xorr = 0;
            for (int j = 0; j < ds[i].size(); j++)
            {
                xorr = xorr ^ ds[i][j];
            }
            total += xorr;
        }

        return total;
    }
};