/**
 * Convert a given tree to to sum tree.
 * Given : A tree with positive and negative data values.
 * Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
 * The values of leaf nodes are changed to 0.
 *            10                             20
 *         /      \                       /       \
 *       -2        6          ---->     4         12
 *      /   \      /  \               /   \      /  \
 *    8     -4    7    5             0    0     0    0
 */

#include <iostream>

struct Node {
  int data;
  Node * left;
  Node * right;
  Node( int d )
  : data{ d },
    left{ nullptr },
    right{ nullptr } { }
};

int  toSumTree( Node * root )
{
  if ( root == nullptr )
  {
    return 0;
  }

  //store the previous value
  int previous_val = root->data;

  // make current node as sum of left and right node. left nodes will become zero
  root->data =  toSumTree(root->left) +  toSumTree(root->right);

  // Now since each node contains the sum of the left and right sub trees in the original tree.
  // we will return the sum of old + new value as sum.
  // Focus on the world original here, and try understanding it from top to bottom.
  return root->data + previous_val;
}

void inorder( Node * root )
{
  if ( root ) {
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
  }
}


int main()
{
  Node * root = new Node(10);
  root->left = new Node(-2);
  root->right = new Node(6);
  root->left->left = new Node(8);
  root->left->right = new Node(-4);
  root->right->left = new Node(7);
  root->right->right = new Node(5);
  std::cout << "Inorder traversal of tree:";
  inorder(root);
  std::cout << "\nAfter transforming to sum tree\n";
   toSumTree(root);
  std::cout << "Inorder traversal of tree:";
  inorder(root);
  std::cout << std::endl;
  return 0;
}
