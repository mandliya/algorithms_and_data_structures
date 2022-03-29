// https : // leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution
{
public:
    int getFirst(vector<int> &nums, int target)
    {
        int start = 0;
        int ans = -1;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                end = mid - 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }

    int getLast(vector<int> &nums, int target)
    {
        int start = 0;
        int ans = -1;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                start = mid + 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> v(2, -1);
        int first = getFirst(nums, target);
        if (first == -1)
        {
            return v;
        }
        int second = getLast(nums, target);

        v[0] = first;
        v[1] = second;
        return v;
    }
};