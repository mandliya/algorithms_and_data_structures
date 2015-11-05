/**
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *			  1
 *			 / \
 *			2   3
 *          The root-to-leaf path 1->2 represents the number 12.
 *          The root-to-leaf path 1->3 represents the number 13.
 *
 *          Return the sum = 12 + 13 = 25.
 */

#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode( int data ) : val{ data }, left{ nullptr }, right{ nullptr } { }
};

void rootToLeafSum( TreeNode* root, int & total, int & curr ) {
	if( root == nullptr ) {
		return;
	}
	curr = (10*curr) + root->val;
	if (root && root->left == nullptr && root->right == nullptr ) {
		total += curr;
	}
	int oldCurr = curr;
	rootToLeafSum(root->left, total, curr);
	rootToLeafSum(root->right, total, oldCurr);
}


int sumNumbers(TreeNode* root) {
	int total = 0;
	int curr = 0;
	rootToLeafSum(root, total, curr);
	return total;
}


void printTree( TreeNode * root ) {
	if ( root ) {
		printTree( root->left );
		std::cout << root->val << " ";
		printTree( root->right );
	}
}


int main() {
	TreeNode * root = new TreeNode( 1 );
	root->left = new TreeNode( 2 );
	root->right = new TreeNode( 3 );
	std::cout << "Tree in order:";
	printTree(root);
	std::cout << "Output : " << sumNumbers(root) << std::endl;
	return 0;
}
