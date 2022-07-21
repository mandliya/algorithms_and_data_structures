// https : // leetcode.com/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mpp;

        for (auto it : nums)
        {
            mpp[it]++;
        }

        for (auto it : mpp)
        {
            if (it.second == 1)
                return it.first;
        }

        return 0;
    }
};