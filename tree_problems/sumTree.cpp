/**
 * Problem: Determine if a tree is sum tree.
 * A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree.
 * An empty tree is SumTree and sum of an empty tree can be considered as 0.
 * A leaf node is also considered as SumTree.
 *
 *         26
 *        /   \
 *      10     3
 *    /    \     \
 *   4      6      3
 */
#include <iostream>

struct Node {
  /* data */
  int data;
  Node * left;
  Node * right;
  Node( int d )
    : data{ d }, left{ nullptr }, right{ nullptr } { }
};

/**
 * addTree - Adds the contents of the tree
 * @param  root
 * @return      total of contents of tree
 */
int addTree( Node * root ) {
  if ( root == nullptr ) {
    return 0;
  }
  return (addTree(root->left) + root->data + addTree(root->right)) ;
}

bool sumTree( Node * root )
{
  if ( root == nullptr ) {
    return true;
  }
  else if ( root->left == nullptr && root->right == nullptr ) {
    return true;
  }
  else {
    if ((addTree(root->left) + addTree(root->right) == root->data) &&
        sumTree(root->left) && sumTree(root->right)) {
        return true;
    } else {
      return false;
    }
  }
}

void inorder(Node * root)
{
    if ( root ) {
      inorder(root->left);
      std::cout << root->data << " ";
      inorder(root->right);
    }
}

int main()
{
/**
  *         26
  *        /   \
  *      10     3
  *    /    \     \
  *   4      6      3
  */
  Node * root = new Node(26);
  root->left = new Node(10);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(6);
  root->right->right = new Node(3);
  std::cout << "Inorder of the tree is :";
  inorder(root);
  std::cout << std::endl;
  std::cout << "Is above tree sum-tree? : ";
  std::cout << ( sumTree(root) ? "Yes\n" : "No\n" );
  return 0;
}
