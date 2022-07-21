/*

 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

 */
class Solution
{
public:
    TreeNode *helper(vector<int> nums, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        int mid = (s + e) / 2;
        int rootData = nums[mid];
        TreeNode *root = new TreeNode(rootData);
        root->left = helper(nums, s, mid - 1);
        root->right = helper(nums, mid + 1, e);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};