/*
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{

private:
    void mark_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
                m[node->left] = node;
            }

            if (node->right != NULL)
            {
                q.push(node->right);
                m[node->right] = node;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> m;
        mark_parents(root, m);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;

        int has_reached_k = 0;

        while (!q.empty())
        {
            int size = q.size();

            if (has_reached_k == k)
            {
                break;
            }

            has_reached_k++;

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if (current->left != NULL and !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if (current->right != NULL and !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (m[current] != NULL and !visited[m[current]])
                {
                    q.push(m[current]);
                    visited[m[current]] = true;
                }
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};