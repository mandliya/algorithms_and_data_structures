/*
 * Validate if a given binary tree is a binary search tree.
 * 
 * Example:
 * 
 *          10
 *       /     \
 *     5       15
 * 
 * Answer: True
 * 
 * Example:
 * 
 *          10
 *       /     \
 *     5        15
 *   /   \     /   \
 *  2     7   9     17
 * 
 * Answer : False                    
 */

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) :
        data{d}, left{nullptr}, right{nullptr} {}
};

bool is_valid_bst(TreeNode* root, TreeNode* min, TreeNode* max)
{
    if (root == nullptr) {
        return true;
    }

    if (min != nullptr && root->data <= min->data) {
        return false;
    }

    if (max != nullptr && root->data >= max->data) {
        return false;
    }

    return is_valid_bst(root->left, min, root) && is_valid_bst(root->right, root, max);

}

bool is_valid_bst(TreeNode* root)
{
    return is_valid_bst(root, nullptr, nullptr);
}

void print_inorder(TreeNode* root)
{
    if (root != nullptr) {
        print_inorder(root->left);
        std::cout << root->data << " ";
        print_inorder(root->right);
    }
}

int main()
{
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);
    std::cout << "Inorder traversal of tree: ";
    print_inorder(root1);
    std::cout << std::endl;
    if (is_valid_bst(root1)) {
        std::cout << "Above tree is a valid binary search tree.\n";  
    } else {
        std::cout << "Above tree is not a valid binary search tree.\n";
    }

    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(9);
    root2->right->right = new TreeNode(17);
     std::cout << "Inorder traversal of tree: ";
    print_inorder(root2);
    std::cout << std::endl;
    if (is_valid_bst(root2)) {
        std::cout << "Above tree is a valid binary search tree.\n";  
    } else {
        std::cout << "Above tree is not a valid binary search tree.\n";
    }
    return 0;
}