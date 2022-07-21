/*
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }

        string str = "";

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == NULL)
            {
                str += "#,";
            }
            else
            {
                str += to_string(node->val) + ",";
            }

            if (node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }

        string str;
        stringstream ss(data);
        getline(ss, str, ',');

        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(ss, str, ',');

            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, str, ',');

            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));