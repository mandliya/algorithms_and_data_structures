// https: // leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int cnt = 0;

        for (auto i : nums)
        {
            m[i]++;
        }

        if (k == 0)
        {
            for (auto x : m)
            {
                if (x.second >= 2)
                {
                    cnt++;
                }
            }

            return cnt;
        }

        for (auto x : m)
        {
            if (m.find(x.first + k) != m.end())
            {
                cnt++;
            }
        }

        return cnt;
    }
};