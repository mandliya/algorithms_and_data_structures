/**
 * Given a binary Tree
 *             1
 *           /   \
 *         2      3
 *       /  \
 *     4     5
 *      \
 *       6
 *
 *   Ancestor of node 6 in root path would be 4, 2, and 1.
 *
 */

#include <iostream>
#include <vector>

struct Node {
	int data;
	Node * left;
	Node * right;
	Node( int d ) : data{ d }, left{ nullptr }, right{ nullptr } { }
};


bool get_ancestors_util( Node * root, int key, std::vector<int> & ancestors ) {
	if ( root == nullptr ) {
		return false;
	}

	if ( root->data == key ) {
		return true;
	}

	if ( get_ancestors_util(root->left, key, ancestors) ||
		 get_ancestors_util(root->right, key, ancestors) ) {
		ancestors.push_back(root->data);
		return true;
	}
	return false;
}

std::vector<int> get_ancestors( Node * root, int key ) {
	std::vector<int> ancestors;
	get_ancestors_util(root, key, ancestors);
	return ancestors;
}

void printAncestors( Node * root ) {
	std::vector<int> vec;
	for ( int i = 1; i <= 6; ++i ) {
		std::cout << "Ancestor of node with key " << i << " are:";
		vec = get_ancestors( root, i );
		for ( auto v : vec ) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
		vec.clear();
	}
}

int main() {
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->right = new Node(6);
	printAncestors(root);
	return 0;
}
