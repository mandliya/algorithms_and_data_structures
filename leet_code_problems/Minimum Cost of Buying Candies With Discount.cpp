// https : // leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int result = 0;
        sort(cost.begin(), cost.end());
        int n = cost.size();
        reverse(cost.begin(), cost.end());
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (count == 2)
            {
                count = 0;
                continue;
            }
            count++;
            result += cost[i];
        }

        return result;
    }
};