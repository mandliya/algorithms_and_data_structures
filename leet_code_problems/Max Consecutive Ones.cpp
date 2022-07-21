// https : // leetcode.com/problems/max-consecutive-ones/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int cnt = 0;
        int max_element = 0;

        for (auto num : nums)
        {
            if (num == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            max_element = max(max_element, cnt);
        }

        return max_element;
    }
};