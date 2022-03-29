// https : // leetcode.com/problems/delete-and-earn/

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        int maxEl = *max_element(nums.begin(), nums.end());
        int dp[20000];
        vector<int> freq(20000);

        for (auto i : nums)
        {
            freq[i]++;
        }

        dp[1] = freq[1];
        dp[2] = max(dp[1], freq[2] * 2);

        for (int i = 3; i <= maxEl; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
        }

        return dp[maxEl];
    }
};