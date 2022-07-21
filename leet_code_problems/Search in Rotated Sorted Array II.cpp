// https : // leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[s] == nums[mid] and nums[mid] == nums[e])
            {
                s++;
                e--;
            }

            else if (nums[s] <= nums[mid])
            {
                if (nums[s] <= target and nums[mid] > target)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }

            else
            {
                if (nums[mid] < target and nums[e] >= target)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }

        return false;
    }
};