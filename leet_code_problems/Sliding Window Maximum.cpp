// https: // leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        int n = nums.size();
        deque<int> q(k);

        int i;

        for (i = 0; i < k; i++)
        {
            while (!q.empty() and nums[i] > nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        for (; i < n; i++)
        {
            result.push_back(nums[q.front()]);

            while (!q.empty() and q.front() <= (i - k))
            {
                q.pop_front();
            }

            while (!q.empty() and nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        result.push_back(nums[q.front()]);
        return result;
    }
};