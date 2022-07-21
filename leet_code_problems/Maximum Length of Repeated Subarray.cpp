// https : // leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        int mx = INT_MIN;

        for (auto i : dp)
        {
            for (auto j : i)
                mx = max(mx, j);
        }

        return mx;
    }
};