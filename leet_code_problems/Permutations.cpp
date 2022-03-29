// https : // leetcode.com/problems/permutations/

class Solution
{
public:
    void findPermute(vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                findPermute(ans, nums, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];

        for (int i = 0; i < nums.size(); i++)
        {
            freq[i] = 0;
        }

        findPermute(ans, nums, ds, freq);

        return ans;
    }
};

/*
// Better Approach

class Solution {
public:

    void findPermutations(vector<int>&nums, vector<vector<int>>&ans, int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            findPermutations(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;

        int idx = 0;

        findPermutations(nums, ans, idx);

        return ans;

    }
};
*/