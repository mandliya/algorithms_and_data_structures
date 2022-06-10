/*
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            m[vertical][level].insert(node->val);

            if (node->left != NULL)
            {
                q.push({node->left, {vertical - 1, level + 1}});
            }

            if (node->right != NULL)
            {
                q.push({node->right, {vertical + 1, level + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto it : m)
        {
            vector<int> ds;

            for (auto data : it.second)
            {
                ds.insert(ds.end(), data.second.begin(), data.second.end());
            }

            ans.push_back(ds);
        }

        return ans;
    }
};