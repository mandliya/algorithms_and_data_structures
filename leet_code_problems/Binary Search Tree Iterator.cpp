/*
 * https://leetcode.com/problems/binary-search-tree-iterator/
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

    void push_left(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        push_left(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        push_left(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */