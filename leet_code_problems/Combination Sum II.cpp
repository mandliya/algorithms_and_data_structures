// https : // leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    void subsequences(vector<vector<int>> &ans, vector<int> &candidates, vector<int> ds, int target, int idx)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx and candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }

            ds.push_back(candidates[i]);
            subsequences(ans, candidates, ds, target - candidates[i], i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        subsequences(ans, candidates, ds, target, 0);

        return ans;
    }
};