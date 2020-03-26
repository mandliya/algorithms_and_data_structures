/*
 * Given a binary search tree, find the kth smallest element in it.
 * Assumption: k is always valid i.e. 1 <= k <= total number of nodes in BST
 *
 *          8
 *        /   \
 *       /     \
 *      4      10
 *     / \     / \
 *    /   \   /   \
 *   2     6 9    12
 *  k = 2, answer: 4
 *  k = 7, answer: 12
 */

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d):
        data{d}, left{nullptr}, right{nullptr} { }
};

int countNodes(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int kthSmallest(TreeNode* root, int k)
{
    int count = countNodes(root->left);
    if (k <= count && root->left) {
        return kthSmallest(root->left, k);
    } else if ( k > count + 1 && root->right) {
        return kthSmallest(root->right, k - count - 1);
    }
    return root->data;
}

void insertNode(TreeNode* &root, int d)
{
    if (!root) {
        TreeNode* newNode = new TreeNode(d);
        root = newNode;
        return;
    }
    if (root->data >= d) {
        insertNode(root->left, d);
    }
    else {
        insertNode(root->right, d);
    }
}

void inorder(TreeNode* root)
{
    if (root) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    TreeNode* root = nullptr;
    insertNode(root, 8);
    insertNode(root, 4);
    insertNode(root, 10);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 9);
    insertNode(root, 12);
    std::cout << "Inorder traversal of tree:" << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "2nd smallest element in tree: " << kthSmallest(root, 2)
        << std::endl;
    std::cout << "4th smallest element in tree: " << kthSmallest(root, 4)
        << std::endl;
    std::cout << "7th smallest element in tree: " << kthSmallest(root, 7)
        << std::endl;
    return 0;
}

