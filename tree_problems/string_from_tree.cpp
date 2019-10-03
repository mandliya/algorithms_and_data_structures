/*
 * Given a binary tree, traversing preorder, construct a string output
 * containing node values and parenthesis.
 * The null node needs to be represented by empty parenthesis pair "()".
 * And you need to omit all the empty parenthesis pairs that don't affect
 * the one-to-one mapping relationship between the string and the original
 * binary tree
 * 
 * Example:
 *              1
 *          /      \
 *        2         3
 *      / \
 *     4   5
 * 
 * Output: 1(2(4)(5))(3)
 * Originally it should be 1(2(4)(5))(3()()), but we are ommiting 
 * all the unnecessary empty parenthesis pairs. 
 * 
 * Example:
 * 
 *         1
 *       /   \
 *      2     3
 *      \  
 *      4
 * Output: 1(2()(4))(3)
 * Here, we can't omit the first parenthesis pair to break
 * the one-to-one mapping relationship between the input and the output.
 * As without empty parenthesis, it would not be clear that 4 is a right child.
 */

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d):
        data{d}, left{nullptr}, right{nullptr}{}
};


std::string string_from_tree(TreeNode* root)
{
    if (root == nullptr) {
        return std::string("");
    }

    if (root->left == nullptr && root->right == nullptr) {
        return std::to_string(root->data);
    }

    if (root->right == nullptr) {
        return std::to_string(root->data) + "(" +
            string_from_tree(root->left) +")";
    }

    return std::to_string(root->data) + "(" +
        string_from_tree(root->left) + ")(" +
        string_from_tree(root->right) + ")";

}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    std::cout << "Tree to string: " << string_from_tree(root)
        << std::endl;
    return 0;
}