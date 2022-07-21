// https : // leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        auto min_num = min_element(nums.begin(), nums.end());
        int min_moves = 0;

        for (auto num : nums)
            min_moves += num - *min_num;

        return min_moves;
    }
};