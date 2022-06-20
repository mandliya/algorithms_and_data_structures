// https : // practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1/#

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> dfs_inorder;

        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                dfs_inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;

                while (prev->right != NULL and prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    dfs_inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return dfs_inorder;
    }
};