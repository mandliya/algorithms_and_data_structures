/**
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *
 */


#include<iostream>
#include<queue>

struct TreeLinkNode {
	int data;
	TreeLinkNode * left;
	TreeLinkNode * right;
	TreeLinkNode * next;
	TreeLinkNode( int d ) : data{ d }, left{ nullptr }, right{ nullptr }, next{ nullptr } {}
};

void connect(TreeLinkNode *root) {
	if( root == nullptr) {
		return;
	}
	std::queue<TreeLinkNode*> qu;
	qu.push(root);
	qu.push(nullptr);
	TreeLinkNode * curr = nullptr;
	while(!qu.empty()) {
		curr = qu.front();
		qu.pop();
		if ( curr == nullptr ) {
			if (!qu.empty()) {
				qu.push(nullptr);
			}
			continue;
		}
		if (!qu.empty()) {
			curr->next = qu.front();
		} else {
			curr->next = nullptr;
		}
		if ( curr->left ) {
			qu.push(curr->left);
		}
		if ( curr->right ) {
			qu.push(curr->right);
		}
	}
}

void printTree( TreeLinkNode * root ) {
	if (root) {
		std::cout << "Node value " << root->data << "-->";
		if ( root->next != nullptr ) {
			std::cout << root->next->data << std::endl;
		} else {
			std::cout << "nullptr" << std::endl;
		}
		printTree(root->left);
		printTree(root->right);
	}
}


int main() {
	TreeLinkNode * root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	std::cout << "Before Connect:\n";
	printTree(root);
	connect(root);
	std::cout << "After Connect:\n";
	printTree(root);
	return 0;
}
