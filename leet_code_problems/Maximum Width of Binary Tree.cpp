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

        int ans = 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int currMin = q.front().second;
            int leftMost, rightMost;

            for (int i = 0; i < size; i++)
            {
                long long currId = q.front().second - currMin;

                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                {
                    leftMost = currId;
                }

                if (i == size - 1)
                {
                    rightMost = currId;
                }

                if (node->left != NULL)
                {
                    q.push({node->left, 2 * currId + 1});
                }

                if (node->right != NULL)
                {
                    q.push({node->right, 2 * currId + 2});
                }
            }

            ans = max(ans, rightMost - leftMost + 1);
        }

        return ans;
    }
};