https : // leetcode.com/problems/two-city-scheduling/

        class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {

        int cnt = 0;

        vector<int> ans;

        for (int i = 0; i < costs.size(); i++)
        {
            cnt += costs[i][0];
            ans.push_back(costs[i][1] - costs[i][0]);
        }

        sort(ans.begin(), ans.end());

        for (int j = 0; j < ans.size() / 2; j++)
        {
            cnt += ans[j];
        }

        return cnt;
    }
};