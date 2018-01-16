/*
 * Given a Binary Search Tree and a target number,
 * return true if there exist two elements in the BST such that their sum is equal to the given target.
 * 
 * Input: 
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 * 
 * Target = 9
 * Output: True
 * 
 * Target = 28
 * Output: False
 * 
 * Approach:
 * 
 * Use a set to insert node values as we traverse the tree. If we find a node such that 
 * k-current_node_val exist already in set, it means we have found a pair of nodes whose values adds up to k.
 * (i.e. current node and node with value k-current_node_val)
 */

#include <iostream>
#include <unordered_set>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d): data{d}, left{nullptr}, right{nullptr}{}
};

bool find_target_k(TreeNode* root, int k, std::unordered_set<int>& set)
{
    if (root == nullptr) {
        return false;
    }

    if (set.find(k - root->data) != set.end()) {
        return true;
    }
    set.insert(root->data);

    return find_target_k(root->left, k, set) || 
        find_target_k(root->right, k, set);
}

bool find_target_k(TreeNode* root, int k)
{
    std::unordered_set<int> set;
    return find_target_k(root, k, set);
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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << "Inorder traversal of the current tree:";
    print_inorder(root);
    std::cout << std::endl;

    if (find_target_k(root, 9)) {
        std::cout << "The tree contains two nodes which adds up to 9\n";
    } else {
        std::cout << "The tree does not contain two nodes which adds up to 9\n";
    }

    if (find_target_k(root, 24)) {
        std::cout << "The tree contains two nodes which adds up to 24\n";
    } else {
        std::cout << "The tree does not contain two nodes which adds up to 24\n";
    }
    return 0;
}