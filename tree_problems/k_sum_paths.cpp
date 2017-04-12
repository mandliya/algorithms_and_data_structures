/*
 * Given a binary tree, print all the paths whose sum is equal to k
 *          1
 *       /     \
 *     3        -1
 *   /   \     /   \
 *  2     1   4     5                        
 *       /   / \     \                    
 *      1   1   2     6
 *
 * For k = 5:
 * 3 2 
 * 3 1 1 
 * 1 3 1 
 * 4 1 
 * 1 -1 4 1 
 * -1 4 2 
 * 5 
 * 1 -1 5     
 */

#include <iostream>
#include <vector>

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) : data {d}, left {nullptr}, right {nullptr} { }
};

void printPath(const std::vector<int>& path, int index)
{
    for (auto it = path.begin() + index; it != path.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printKPaths(TreeNode * node, std::vector<int>& paths, int k)
{
    if (!node)
    {
        return;
    }

    // push the current node to paths
    //
    paths.push_back(node->data);

    // now, lets explore the left and right sub-trees
    //
    printKPaths(node->left, paths, k);
    printKPaths(node->right, paths, k);

    // check if we have reached sum of tree nodes to k.
    // also, do not break, once we have reached k, as we may have negative
    // values too.
    //
    /*
    int sum = 0;
    for (int j=paths.size()-1; j>=0; j--)
    {
        sum += (paths[j]);
        if (sum == k)
        {
            printPath(paths, j);
        }
    }
    */
    int sum = 0;
    for (auto it = paths.rbegin(); it != paths.rend(); ++it)
    {
        sum += (*it);
        if (sum == k)
        {
            int indexFromStart = paths.size() - 1 - (it - paths.rbegin());
            printPath(paths, indexFromStart);
        }
    }

    paths.pop_back();
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(-1);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(2);

    int k = 5;
    std::vector<int> paths;
    printKPaths(root, paths, k);
    return 0;
}