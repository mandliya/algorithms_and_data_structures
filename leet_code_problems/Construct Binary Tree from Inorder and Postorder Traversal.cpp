/*

 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *helper(vector<int> inOrder, vector<int> postOrder, int inS, int inE, int postS, int postE)
    {

        if (inS > inE)
        {
            return NULL;
        }

        int rootData = postOrder[postE];
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
        int leftPostS = postS;
        int leftPostE = leftInE + leftPostS - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = inE;
        int rightPostS = leftPostE + 1;
        int rightPostE = postE - 1;

        TreeNode *root = new TreeNode(rootData);
        root->left = helper(inOrder, postOrder, leftInS, leftInE, leftPostS, leftPostE);
        root->right = helper(inOrder, postOrder, rightInS, rightInE, rightPostS, rightPostE);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = postorder.size();
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};