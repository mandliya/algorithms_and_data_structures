/*
Given a binary tree (consisting of N nodes and X values), find the depth and
height of the node with value X.

Depth of a node is the number of nodes from the root node to the intended node.

Height of a node is the number of nodes connecting the intended node to the
leaf/lowest node.

                            15
						  /    \
						 /      \
						/        \
					   7          6
				      / \	     / \
					25   34	    82  90
				   / \               \
                 66   58              110
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

// Function to create a new node
Node *CreateNode(int item) {
  Node *temp = new Node;
  temp->data = item;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// Function to find the depth of a node
int FindDepth(Node *root01, int x) {
  if (root01 == NULL)
    return -1;

  int res = -1;

  if ((root01->data == x) || (res = FindDepth(root01->left, x)) >= 0 ||
      (res = FindDepth(root01->right, x)) >= 0)
    return res + 1;

  return res;
}

int FindHeightUtil(Node *root01, int x, int &h) {
  if (root01 == NULL) {
    return -1;
  }

  int LeftHeight = FindHeightUtil(root01->left, x, h);

  int RightHeight = FindHeightUtil(root01->right, x, h);

  int res = max(LeftHeight, RightHeight) + 1;

  if (root01->data == x) {
    h = res;
  }

  return res;
}

// Function to find the height of a node
int FindHeight(Node *root01, int x) {
  int h = -1;

  int MaxHeight = FindHeightUtil(root01, x, h);

  return h;
}

// Main Driver
int main() {
  // Create a binary tree
  Node *root01 = CreateNode(15);
  root01->left = CreateNode(7);
  root01->right = CreateNode(6);
  root01->left->left = CreateNode(25);
  root01->left->right = CreateNode(34);
  root01->left->right->left = CreateNode(66);
  root01->left->right->right = CreateNode(58);
  root01->right->left = CreateNode(82);
  root01->right->right = CreateNode(90);
  root01->right->right->right = CreateNode(110);

  int x = 34;

  // Call FindDepth function
  cout << "Depth of Node: " << FindDepth(root01, x) << "\n";

  // Call FindHeight function
  cout << "Heigth of Node: " << FindHeight(root01, x) << "\n";

  return 0;
}