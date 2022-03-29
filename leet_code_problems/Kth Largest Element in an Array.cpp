// https : // leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    // Returns the index of pivot element
    // The pivot element after this function will be at correct position
    // if the array was sorted in decreasing order
    int partition(vector<int> &nums, int l, int r)
    {
        // Using nums[r] as the pivot
        int prev = l - 1;
        for (int i = l; i < r; ++i)
        {
            if (nums[i] >= nums[r])
            {
                prev++;
                swap(nums[prev], nums[i]);
            }
        }
        prev++;
        swap(nums[prev], nums[r]);
        return prev;
        // Return index of element at correct position
    }

    // Returns the Kth largest element
    int quicksort(vector<int> &nums, int k, int l, int r)
    {
        // Partition subroutine
        int part = partition(nums, l, r);
        // If correct element found
        if (part + 1 == k)
            return nums[part];

        // If the index found overshot the required answer, recursively do the left part
        if (part + 1 > k)
            return quicksort(nums, k, l, part - 1);
        // Otherwise, recursively do the right part
        return quicksort(nums, k, part + 1, r);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quicksort(nums, k, 0, n - 1);
    }
};