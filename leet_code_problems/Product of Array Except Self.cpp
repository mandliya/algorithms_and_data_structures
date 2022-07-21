// https : // leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dot(n, 1);
        int right = 1;

        for (int i = 1; i < n; i++)
        {
            dot[i] = nums[i - 1] * dot[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            dot[i] = right * dot[i];
            right = nums[i] * right;
        }

        return dot;
    }
};