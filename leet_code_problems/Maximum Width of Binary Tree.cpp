// https : // leetcode.com/problems/maximum-width-of-binary-tree/

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
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int width = 0;

        while (!q.empty())
        {
            int n = q.size();
            int first;
            int last;

            for (int i = 0; i < n; i++)
            {
                long long curr_idx = q.front().second;
                TreeNode *f = q.front().first;
                q.pop();

                if (i == 0)
                {
                    first = curr_idx;
                }
                if (i == n - 1)
                {
                    last = curr_idx;
                }
                if (f->left)
                {
                    q.push({f->left, curr_idx * 2 + 1});
                }

                if (f->right)
                {
                    q.push({f->right, curr_idx * 2 + 2});
                }
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};