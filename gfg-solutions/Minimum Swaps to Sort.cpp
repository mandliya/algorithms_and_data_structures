// https : // practice.geeksforgeeks.org/problems/minimum-swaps/1

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size(), swaps = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = make_pair(nums[i], i);
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            while (v[i].second != i)
            {
                swap(v[i], v[v[i].second]);
                ++swaps;
            }
        return swaps;
    }
};