// https : // leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        for (auto num : nums)
            sum += num;

        if (sum % 2 == 1)
            return false;

        sum = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }
};