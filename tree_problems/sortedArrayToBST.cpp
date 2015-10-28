/**
 * Given a sorted array, convert it balaned binary search tree.
 */

#include<iostream>
#include<vector>

struct Node {
	int data;
	Node * left;
	Node * right;
	Node( int d ) : data{ d }, left{ nullptr }, right{ nullptr } { }
};

Node * sortedArrayToBST( std::vector<int> & arr, int start, int end ) {
	if ( start > end ) {
		return nullptr;
	}
	int mid = ( start + end )/2;
	Node * node = new Node(arr[mid]);
	node->left = sortedArrayToBST( arr, start, mid - 1 );
	node->right = sortedArrayToBST( arr, mid + 1, end );
	return node;
}

void printArray( std::vector<int> & arr ) {
	for ( auto i : arr ) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void printTreeInOrder( Node * root ) {
	if( root ) {
		printTreeInOrder( root->left );
		std::cout << root->data << " ";
		printTreeInOrder( root->right );
	}
}

int main() {
	std::vector<int> arr{ 1, 2, 3, 4, 5, 6, 7, 8 };
	std::cout << "Arr  :";
	printArray(arr);
	Node * root = sortedArrayToBST(arr, 0, arr.size() - 1);
	std::cout << "Tree :";
	printTreeInOrder(root);
	std::cout << std::endl;
	return 0;
}
