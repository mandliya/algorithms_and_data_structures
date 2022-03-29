// https : // leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {

        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] and (i * j) % k == 0)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};