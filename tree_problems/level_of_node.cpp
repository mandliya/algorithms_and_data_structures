/**
 * Given a Binary Tree and a key, write a function that returns level of the key.
 * 				3
 * 			/		\
 * 			2		5
 * 		/		\
 * 		1		4
 *
 * 	Here 3 is on level 1
 * 	2 and 5 have level 2
 * 	1 and 4 have level 3
 * 	If key not in tree, return 0
 *
 */
#include <iostream>
struct Node {
	int data;
	Node * left;
	Node * right;
	Node( int d ) : data{ d }, left{ nullptr }, right{ nullptr } { }
};

int get_node_level_util( Node * root, int key, int level ) {
	if ( root == nullptr ) {
		return 0;
	}
	if ( root->data == key ) {
		return level;
	}
	int downlevel = get_node_level_util( root->left, key, level + 1);
	if ( downlevel != 0 ) {
		return downlevel;
	}
	downlevel = get_node_level_util( root->right, key, level + 1);
	return downlevel;
}

int get_node_level( Node * root, int key ) {
	return get_node_level_util( root, key, 1 );
}

void printLevels(Node * root) {
	for ( int i = 1; i <= 6; ++i ) {
		std::cout << "Level of node with key as " << i << " is " << get_node_level( root, i ) << std::endl;
	}
}

int main() {
	Node * root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	printLevels(root);
	return 0;
}
