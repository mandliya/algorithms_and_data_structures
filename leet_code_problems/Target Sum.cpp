// https : // leetcode.com/problems/target-sum/

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        target = abs(target);
        int n = nums.size();

        for (auto num : nums)
            sum += num;

        if (sum < target or (sum + target) % 2 != 0)
            return 0;

        int s1 = (target + sum) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < s1 + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < s1 + 1; j++)
            {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][s1];
    }
};