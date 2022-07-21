// https: // leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());

        if (nums.size() == s.size())
        {
            return false;
        }

        return true;
    }
};