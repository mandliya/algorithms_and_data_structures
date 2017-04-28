/*
 * Given a BST, find ceil and floor of a given key in it. If the given key lie in the BST,
 * then both floor and ceil is equal to that key, else ceil is equal to next greater key (if any) 
 * in the BST and floor is equal to previous greater key (if any) in the BST.
 * source : techiedelight.com
 *
 *          8
 *        /   \
 *       /     \
 *      4      10
 *     / \     / \
 *    /   \   /   \
 *   2     6 9    12
 * floor of 1 do not exist, ceil of 1 is 2
 * floor of 3 is 2, ceil of 3 is 4
 * floor of 9 is 9, ceil of 9 is 9
 * floor of 7 is 6, ceil of 7 is 8
 *
 * Approach: Search for the key in BST, every time we narrow down a subtree where key might belong,
 * We update the ceil if we choose left-subtree, and we update floor if choose right-subtree
 * If the key is not in the tree, we will have updated floor and ceil values.
 */


#include <iostream>

struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int d)
        : key {d} 
        , left {nullptr}
        , right {nullptr}{}
};

void insertNode(TreeNode* &root, int d)
{
    if (!root)
    {
        TreeNode* newNode = new TreeNode(d);
        root = newNode;
        return;
    }
    
    if (root->key >= d)
    {
        insertNode(root->left, d);
    }
    else
    {
        insertNode(root->right, d);
    }
}

void findFloorCeil(TreeNode* root, int& floor, int& ceil, int key)
{
    if (!root)
    {
        return;
    }

    if (root->key == key)
    {
        floor = ceil = key;
    }

    else if (key < root->key)
    {
        ceil = root->key;
        findFloorCeil(root->left, floor, ceil, key);
    }

    else
    {
        floor = root->key;
        findFloorCeil(root->right, floor, ceil, key);
    }
}

void inOrder(TreeNode* root)
{
    if (root)
    {
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);
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
    std::cout << "InOrder traversal of the tree:\n";
    inOrder(root);
    std::cout << std::endl;
    
    int keyToSearch = 3;
    int floor = -1;
    int ceil = -1;
    findFloorCeil(root, floor, ceil, keyToSearch);
    std::cout << "For key = "<< keyToSearch << " floor is "
        << floor << " and ceil is " << ceil << std::endl;
    
    keyToSearch = 9;
    // Reset floor and ceil
    floor = -1;
    ceil = -1;
    findFloorCeil(root, floor, ceil, keyToSearch);
    std::cout << "For key = "<< keyToSearch << " floor is "
        << floor << " and ceil is " << ceil << std::endl;

    return 0;
}