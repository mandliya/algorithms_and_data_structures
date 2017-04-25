/*
 * Invert given Binary Tree | Recursive and Iterative solution
 *                  1                         1
 *              /       \                 /       \
 *             2         3      ->       3         2
 *           /   \     /   \           /   \     /   \
 *          4     5   6     7         7     6   5     4
 *
 */

#include <bits/stdc++.h>

 struct TreeNode
 {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int d)
        : data{d}, left{nullptr}, right{nullptr} {}
 };

void invertTreeRecur(TreeNode* root)
{
    if (!root)
    {
        return;
    }

    // Swap left and right trees
    //
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Do this recursively for left and right sub-trees.
    //
    invertTreeRecur(root->left);
    invertTreeRecur(root->right);
}

void invertTreeIter(TreeNode* root)
{
    if (!root)
    {
        return;
    }
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty())
    {
        TreeNode* curr = nodeQueue.front();
        nodeQueue.pop();

        // Swap left and right children
        //
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        if (curr->left)
        {
            nodeQueue.push(curr->left);
        }

        if (curr->right)
        {
            nodeQueue.push(curr->right);
        }
    }
}

// Prints post order traversal of tree, where level expands left to right.
//
void postOrder(TreeNode* root, int indent = 0)
{
    if (root)
    {
        if(root->right)
        {
            postOrder(root->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (root->right)
        {
            std::cout<<" /\n" << std::setw(indent) << ' ';
        }
        std::cout<< root->data << "\n ";
        if(root->left)
        {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postOrder(root->left, indent + 4);
        }
    }
}

 int main()
 {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    std::cout << "Current Tree: \n";
    postOrder(root);
    std::cout << "\nInverting it recursively:\n";
    invertTreeRecur(root);
    postOrder(root);
    std::cout << "\nInverting it again iteratively:\n";
    invertTreeIter(root);
    postOrder(root);
    std::cout << std::endl;
    return 0;
 }