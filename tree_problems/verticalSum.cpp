/**
 * Given a binary Tree
 * 		    1
 * 		 /     \
 * 	       2	 3
 * 	     /	 \	/ \
 *  	    4	  5    6   7
 *
 *  Find vertical sums of the tree.
 *  Align the nodes in vertical line.
 *  Here
 *  The tree has 5 vertical lines
 *
 *  Vertical-Line-1 has only one node 4 => vertical sum is 4
 *  Vertical-Line-2: has only one node 2=> vertical sum is 2
 *  Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
 *  Vertical-Line-4: has only one node 3 => vertical sum is 3
 *  Vertical-Line-5: has only one node 7 => vertical sum is 7
 *
 *  So expected output is 4, 2, 12, 3 and 7
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

struct Node {
	int data;
	Node * left;
	Node * right;
	Node ( int d ) : data{ d }, left{ nullptr }, right{ nullptr } { }
};

void vertical_sum_util( Node * root, int dist, std::unordered_map<int,int> & vmap) {
	if ( root == nullptr )  {
		return ;
	}
	if ( vmap.find(dist) != vmap.end() )  {
		vmap[dist] += root->data;
	} else {
		vmap[dist] = root->data;
	}
	vertical_sum_util( root->left, dist-1, vmap);
	vertical_sum_util( root->right, dist+1, vmap);
}

void vertical_sum( Node * root ) {
	if ( root == nullptr )  {
		return;
	}
	std::unordered_map<int, int> vmap;
	vertical_sum_util( root, 0, vmap );
	std::map<int, int> ordered( vmap.begin(), vmap.end());
	std::cout << "Printing vertical sum values, first column represent the position of vertical column with respect to root(0)\n"
			  << "and second column represent vertical sum for that column\n";
	for ( auto it = ordered.begin(); it != ordered.end(); ++it ) {
		std::cout << it->first << "	" << it->second << std::endl;
	}
}

int main() {
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	vertical_sum(root);
	return 0;

}
