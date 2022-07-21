// https : // leetcode.com/problems/subsets-ii/

class Solution
{
public:
    void genSubsets(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int idx)
    {
        ans.push_back(ds); // no need of base case, just push an empty vector initially.

        for (int i = idx; i < nums.size(); i++)
        {
            if (idx != i and nums[i] == nums[i - 1]) // make sure we can not pick repeated elements (that's why we have sorted the vector).
            {                                        // idx!=i this indicates that we are picking the element only when idx and i are eqaul for the first time.
                continue;
            }
            ds.push_back(nums[i]);            // pickup up the element.
            genSubsets(nums, ds, ans, i + 1); // make a call including that element
            ds.pop_back();                    // remove that element and the loop will be executed again and another call will be made excluding that element.
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        int idx = 0;

        sort(nums.begin(), nums.end()); // sort in order to make sure that repeated elements can be one after other, so we can skip them.

        genSubsets(nums, ds, ans, idx);

        return ans;
    }
};