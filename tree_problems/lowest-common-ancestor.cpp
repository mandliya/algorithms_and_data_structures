/**
 *  Given a binary search tree, determine the lowest common ancestor of two given nodes with data
 *  key1 and key2. Assumption is key1 and key2 exists in tree
 *  Example
 *            20
 *        /        \
 *        8        22
 *    /      \
 *    4        12
 *          /     \
 *        10     14
 *
 * In the above tree, LCA of 10 and 14 is 12
 * similarly 4 and 22 will have LCA 20
 */

#include <iostream>

struct Node {
  int data;
  Node * left = nullptr;
  Node * right = nullptr;
  Node (int d) :
    data{ d }, left{ nullptr }, right{ nullptr } { }
};

Node * lca ( Node * root, int key1, int key2 ) {
  if ( root == nullptr ) {
    return nullptr;
  }
  if (root->data > key1 && root->data > key2) {
    return lca(root->left, key1, key2);
  } else if ( root->data < key1 && root->data < key2 ) {
    return lca(root->right, key1, key2);
  }
  return root;
}


void inorder(Node * root)
{
    if (root) {
      inorder(root->left);
      std::cout << root->data << "  ";
      inorder(root->right);
    }
}

int main()
{
  Node * root = new Node(20);
  root->right = new Node(22);
  root->left = new Node(8);
  root->left->left = new Node(4);
  root->left->right= new Node(12);
  root->left->right->right = new Node(14);
  root->left->right->left = new Node(10);
  std::cout << "Inorder traversal of the tree:";
  inorder(root);
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "LCA of nodes with data 10 and 14 is :"
            << (lca(root, 14, 10))->data << std::endl;
  std::cout << "LCA of nodes with data 14 and 8 is :"
            << (lca(root, 14, 8))->data << std::endl;
  std::cout << "LCA of root with data 4 and 22 is :"
            << (lca(root, 4, 22))->data << std::endl;
  std::cout << "LCA of root with data 14 and 10 is :"
            << (lca(root, 10, 14))->data << std::endl;
  return 0;
}
