//  https://leetcode.com/problems/binary-tree-inorder-traversal/

/* Recursive
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
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};

/** Iterative
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
    vector<int> inorderTraversal(TreeNode *root)
    {

        stack<TreeNode *> st;
        TreeNode *n = root;
        vector<int> ds;

        while (true)
        {
            if (n != NULL)
            {
                st.push(n);
                n = n->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }

                n = st.top();
                st.pop();
                ds.push_back(n->val);
                n = n->right;
            }
        }

        return ds;
    }
};