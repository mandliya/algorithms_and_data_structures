/*
 * Reverse Level Order Traversal of Binary Tree
 * Given a binary tree, print its nodes level by level in reverse order.
 * i.e. all nodes present at last level should be printed first followed
 * by nodes of second-last level and so on..
 * All nodes for any level should be printed from left to right.
 *
 *               1
 *             /   \
 *            2     3
 *           / \   / \
 *          4  5  6   7
 *
 * The reverse level order traversal of the tree is : 
 * 4, 5, 6, 7, 2, 3, 1 
 */




#include <iostream>
#include <stack>
#include <queue>


struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int d)
        : data {d}
        , left {nullptr}
        , right {nullptr} {}
};

void printReverseLevelOrder(TreeNode* root)
{
    if (!root)
    {
        return;
    }

    // Idea is to do a level order traversal and then 
    // push the nodes in a stack, so we can print in 
    // reverse order.
    //
    std::queue<TreeNode*> nodeQueue;
    std::stack<TreeNode*> nodeStack;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        TreeNode* curr = nodeQueue.front();
        nodeQueue.pop();
        nodeStack.push(curr);

        // We will push right node first, as we want to print
        // reverse level order traversal.
        //
        if (curr->right)
        {
            nodeQueue.push(curr->right);
        }

        if (curr->left)
        {
            nodeQueue.push(curr->left);
        }
    }

    std::cout << "Reverse level order traversal:";
    while (!nodeStack.empty())
    {
        TreeNode* curr = nodeStack.top();
        std::cout << curr->data << " ";
        nodeStack.pop();
    }
    std::cout << std::endl;
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    printReverseLevelOrder(root);
    return 0;
}