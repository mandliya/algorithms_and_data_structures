/*
 * Given a non-empty binary search tree and a target value, 
 * find the value in the BST that is closest to the target.
 * Also, to note that the target value is a floating point.
 * There will be only one unique value which is closest to the target.
 */

#include <iostream>
#include <limits>
#include <cmath>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d):
        data{d}, left{nullptr}, right{nullptr}{}
};



int closest_bst_value(TreeNode* root, double target)
{
    // Tree is non-empty, so root is always valid.
    int curr_value = root->data;
    TreeNode* child = (target < curr_value) ? (root->left) : (root->right);
    if (!child) {
        return curr_value;
    }
    int child_value = closest_bst_value(child, target);
    return std::abs(curr_value - target) <
        std::abs(child_value- target) ? curr_value : child_value;
}

int closest_bst_value_iterative(TreeNode* root, double target)
{
    int closest = root->data;
    while (root != nullptr)
    {
        if (std::abs(target - closest) >= std::abs(target - root->data)) {
            closest = root->data;
        }
        root = target < root->data ? root->left : root->right;
    }
    return closest;
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
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new  TreeNode(12);
    root->right->right = new TreeNode(16);

    std::cout << "Inorder traversal of tree: ";
    print_inorder(root);
    std::cout << std::endl;
    std::cout << "Closest value from 3.6778 is :" << closest_bst_value(root, 3.6778)
        << std::endl;
    
    std::cout << "(Iterative) Closest value from 3.6778 is :"
        << closest_bst_value_iterative(root, 3.6778) << std::endl;
    return 0;
}