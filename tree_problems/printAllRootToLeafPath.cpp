/**
 *  Given a binary tree, print out all root to leaf path, one per line.
 *  Example :
 *              1
 *          /      \
 *        2         3
 *      / \
 *     4   5
 *  	Possible paths in above tree:
 *  	1 2 4
 *  	1 2 5
 *  	1 3
 */

#include <iostream>
#include <vector>

struct Node {
  int data;
  Node * left;
  Node * right;
  Node(int d) : data{ d }, left{ nullptr }, right{ nullptr } { }
};


void printPath( const std::vector<int> & vec )
{
  for (const int i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void printPaths( Node * node, std::vector<int> paths )
{
    if ( node == nullptr ) {
      return;
    }
    //push data to path
    paths.push_back(node->data);
    //leaf node
    if ( node->left == nullptr && node->right == nullptr ) {
      printPath(paths);
    } else {
      printPaths(node->left, paths);
      printPaths(node->right, paths);
    }
}

int main()
{
  Node * root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  std::vector<int> vec;
  printPaths(root, vec);
  return 0;
}
