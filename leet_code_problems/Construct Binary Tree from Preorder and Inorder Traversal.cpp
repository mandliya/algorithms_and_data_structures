/*

 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode *helper(vector<int> preOrder, vector<int> inOrder, int inS, int inE, int preS, int preE)
    {
        if (inS > inE)
        {
            return NULL;
        }

        int rootData = preOrder[preS];
        int rootIndex = -1;

        for (int i = inS; i <= inE; i++)
        {
            if (inOrder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }

        int leftInS = inS;
        int leftInE = rootIndex - 1;
        int leftPreS = preS + 1;
        int leftPreE = leftPreS + leftInE - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = inE;
        int rightPreS = leftPreE + 1;
        int rightPreE = preE;

        TreeNode *root = new TreeNode(rootData);
        root->left = helper(preOrder, inOrder, leftInS, leftInE, leftPreS, leftPreE);
        root->right = helper(preOrder, inOrder, rightInS, rightInE, rightPreS, rightPreE);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};