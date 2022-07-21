// https : // leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            totalSum = max(currSum, totalSum);
        }
        return totalSum;
    }
};