/*
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode *helper(vector<int> inorder, int inStart, int inEnd, vector<int> preorder, int preStart, int preEnd, unordered_map<int, int> inMap)
    {
        if (inStart > inEnd or preStart > preEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int in_root = inMap[root->val];
        int nums_left = in_root - inStart;

        root->left = helper(inorder, inStart, in_root - 1, preorder, preStart + 1, preStart + nums_left, inMap);
        root->right = helper(inorder, in_root + 1, inEnd, preorder, preStart + nums_left + 1, preEnd, inMap);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        TreeNode *root = helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inMap);

        return root;
    }
};