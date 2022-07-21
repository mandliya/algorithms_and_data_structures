/**
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
class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool is_reverse;

    void push_all(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            if (is_reverse == true)
                root = root->right;
            else
                root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root, bool is_reverse)
    {
        this->is_reverse = is_reverse;
        push_all(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (is_reverse == true)
            push_all(node->left);
        else
            push_all(node->right);
        return node->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};