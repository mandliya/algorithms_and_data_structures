// https : // leetcode.com/problems/binary-tree-preorder-traversal/

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
    void preOrder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }

        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        preOrder(root, v);
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
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> ds;

        stack<TreeNode *> st;

        if (root == NULL)
        {
            return ds;
        }

        st.push(root);

        while (!st.empty())
        {
            TreeNode *n = st.top();
            st.pop();

            ds.push_back(n->val);

            if (n->right != NULL)
            {
                st.push(n->right);
            }

            if (n->left != NULL)
            {
                st.push(n->left);
            }
        }

        return ds;
    }
};