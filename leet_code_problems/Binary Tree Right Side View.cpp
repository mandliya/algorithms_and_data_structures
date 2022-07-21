/*
 * https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root)
    {

        vector<vector<int>> ans;

        vector<int> anss;
        if (root == NULL)
        {
            return anss;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ds(size);

            for (int i = 0; i < size; i++)
            {
                int idx = size - i - 1;

                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }

                ds[idx] = node->val;
            }

            ans.push_back(ds);
        }

        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                anss.push_back(ans[i][0]);
                break;
            }
        }

        return anss;
    }
};

/*
 * Recursive
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
    void getRightView(TreeNode *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
        {
            return;
        }

        if (lvl == ans.size())
        {
            ans.push_back(root->val);
        }

        getRightView(root->right, ans, lvl + 1);
        getRightView(root->left, ans, lvl + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> ans;

        getRightView(root, ans, 0);

        return ans;
    }
};