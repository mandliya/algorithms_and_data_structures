// https : // leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        unordered_map<int, int> m;

        for (auto i : nums)
        {
            m[i]++;
        }

        int i = 0;

        for (auto it : m)
        {
            if (it.second == 1)
            {
                return it.first;
            }
        }

        return 0;
    }
};