// https : // leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        unordered_map<int, int> m;

        for (auto i : nums)
        {
            m[i]++;
        }

        for (auto j : m)
        {
            if (j.second > 1)
            {
                return j.first;
            }
        }

        return 0;
    }
};