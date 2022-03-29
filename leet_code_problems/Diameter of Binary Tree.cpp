/*

 * https://leetcode.com/problems/diameter-of-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int case1 = height(root->left) + height(root->right);
        int case2 = diameterOfBinaryTree(root->left);
        int case3 = diameterOfBinaryTree(root->right);
        return max(case1, max(case2, case3));
    }
};

*/

// BETTER APPROACH (always use the following)

/*

 * https://leetcode.com/problems/diameter-of-binary-tree/
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
    pair<int, int> heightDiameter(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> leftTotal = heightDiameter(root->left);
        pair<int, int> rightTotal = heightDiameter(root->right);

        int lh = leftTotal.first;
        int ld = leftTotal.second;

        int rh = rightTotal.first;
        int rd = rightTotal.second;

        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));

        pair<int, int> p;
        p.first = height;
        p.second = diameter;

        return p;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        pair<int, int> p = heightDiameter(root);
        return p.second;
    }
};