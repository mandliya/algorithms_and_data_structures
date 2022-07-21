// https : // leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        unordered_map<int, int> m;
        int n = nums.size();
        int result = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            if (currSum == k)
            {
                result++;
            }

            if (m.find(currSum - k) != m.end())
            {
                result += m[currSum - k];
            }
            m[currSum]++;
        }
        return result;
    }
};