/*
 * We did lowest common ancestor of a binary SEARCH tree in a different problem.
 * This will provide lowest common ancestor of a binary tree.
 *  Example
 *            20
 *        /        \
 *       24        22
 *    /      \
 *   25        12
 *          /     \
 *        10     14
 *
 * In the above tree, LCA of 10 and 14 is 12
 * similarly 14 and 25 will have LCA 24
 * LCA of 10 and 22 is 20.
 */

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d):
        data{ d }, left{ nullptr }, right{ nullptr }{ }
};

void inorder(TreeNode * root)
{
    if (root) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr || p == root || q == root) {
        return root;
    }

    TreeNode* leftLCA = lowest_common_ancestor(root->left, p, q);
    TreeNode* rightLCA = lowest_common_ancestor(root->right, p, q);
    return (!leftLCA ? rightLCA : !rightLCA ? leftLCA : root);
}

int main()
{
    // Lets create the tree in example
    
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(24);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    std::cout << "Inorder Traversal of the tree:" << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "The LCA of nodes with values 10 and 14 is:"
        << lowest_common_ancestor(root, root->left->right->left, root->left->right->right)->data 
        << std::endl;

    std::cout << "The LCA of nodes with values 25 and 14 is:"
        << lowest_common_ancestor(root, root->left->left, root->left->right->right)->data 
        << std::endl;

     std::cout << "The LCA of nodes with values 10 and 22 is:"
        << lowest_common_ancestor(root, root->left->right->left, root->right)->data 
        << std::endl;
    return 0;
}