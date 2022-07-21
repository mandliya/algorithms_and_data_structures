// https : // leetcode.com/problems/combination-sum/

class Solution
{
public:
    void helper(vector<int> &candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &result)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                result.push_back(temp);
            }
            return;
        }

        if (candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], idx, temp, result);
            temp.pop_back();
        }

        helper(candidates, target, idx + 1, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> result;
        vector<int> temp;
        helper(candidates, target, 0, temp, result);
        return result;
    }
};