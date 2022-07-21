// https : // leetcode.com/problems/flatten-binary-tree-to-linked-list/

// 1. Recursion
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution
{
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

// 2. Stack
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            if (curr != NULL and curr->right != NULL)
            {
                st.push(curr->right);
            }

            if (curr != NULL and curr->left != NULL)
            {
                st.push(curr->left);
            }

            if (!st.empty())
            {
                curr->right = st.top();
                curr->left = NULL;
            }
        }
    }
};

// 3. Morris Traversal(No Extra Space)
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *prev = curr->left;

                while (prev->right != NULL)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};