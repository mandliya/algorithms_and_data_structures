// https : // leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> s;
        int n = nums.size();

        if (nums.empty())
        {
            return 0;
        }

        for (auto x : nums)
        {
            s.insert(x);
        }

        int largestLength = 1;

        for (auto element : s)
        {
            int parent = element - 1;
            if (s.find(parent) == s.end())
            {
                int nextElement = element + 1;
                int count = 1;
                while (s.find(nextElement) != s.end())
                {
                    count++;
                    nextElement++;
                }

                if (count > largestLength)
                {
                    largestLength = count;
                }
            }
        }

        return largestLength;
    }
};