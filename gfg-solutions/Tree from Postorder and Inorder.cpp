// https : // practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1#

Node *helper(int in[], int inStart, int inEnd, int post[], int postStart, int postEnd, unordered_map<int, int> &inMap)
{
    if (inStart > inEnd or postStart > postEnd)
    {
        return NULL;
    }

    Node *root = new Node(post[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = helper(in, inStart, inRoot - 1, post, postStart, postStart + numsLeft - 1, inMap);
    root->right = helper(in, inRoot + 1, inEnd, post, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    unordered_map<int, int> inMap;

    for (int i = 0; i < n; i++)
    {
        inMap[in[i]] = i;
    }

    Node *root = helper(in, 0, n - 1, post, 0, n - 1, inMap);

    return root;
}