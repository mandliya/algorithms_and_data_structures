// https : // leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int sum = 0, res = 0;

        for (int i = 0; i < k; i++)
            res += cardPoints[i];

        sum = res;

        for (int i = k - 1; i >= 0; i--)
        {
            sum -= cardPoints[i];
            sum += cardPoints[cardPoints.size() - k + i];

            res = max(res, sum);
        }

        return res;
    }
};