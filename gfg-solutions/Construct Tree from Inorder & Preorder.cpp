// https : // practice.geeksforgeeks.org/problems/construct-tree-1/1#

class Solution
{
public:
    Node *helper(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd, map<int, int> &inMap)
    {
        if (inStart > inEnd or preStart > preEnd)
        {
            return NULL;
        }

        Node *root = new Node(pre[preStart]);

        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;

        root->left = helper(pre, preStart + 1, preStart + numsLeft, in, inStart, inRoot - 1, inMap);
        root->right = helper(pre, preStart + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, inMap);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        map<int, int> inMap;

        for (int i = 0; i < n; i++)
        {
            inMap[in[i]] = i;
        }

        Node *root = helper(pre, 0, n - 1, in, 0, n - 1, inMap);

        return root;
    }
};