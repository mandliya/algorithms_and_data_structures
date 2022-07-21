// https : // leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int median = nums[n / 2];
        int min_moves = 0;

        for (int i = 0; i < n; i++)
            min_moves += abs(nums[i] - median);

        return min_moves;
    }
};