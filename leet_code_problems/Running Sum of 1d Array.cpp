// https : // leetcode.com/problems/running-sum-of-1d-array/

class Solution
{
public:
    vector<int> runningSum(vector<int> &ans)
    {

        for (int i = 1; i < ans.size(); i++)
        {
            ans[i] = ans[i - 1] + ans[i];
        }

        return ans;
    }
};