/*
 *  Goal : To find successor and predecessor ( if exists ) of a key in Binary Search Tree
 *
 */

#include <iostream>
#include <generic.h>

/* Node of the tree */
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Helper function to return a new node
Node* newNode( const int & data )
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

//insert to a binary tree
void insert( Node * & node, const int & data )
{
    if ( node == nullptr ) {
        node = newNode(data);
        return;
    }
    
    if ( data < node->data ) {
        insert( node->left, data);
    } else {
        insert( node->right, data);
    }
}

// print inorder traversal of the tree
void inorder( Node * node)
{
    if ( node != nullptr )
    {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void predecessorSuccessor( Node *node, Node * &pred, Node * & succ, int key )
{
    if ( node == nullptr )
        return;

    if ( node->data == key )
    {
        if (node->left) {
            Node *temp = node->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }

        if (node->right) {
            Node * temp = node->right;
            while (temp->left)
                temp = temp->left;
            succ = temp;
        }
    } else if ( key < node->data ) {
        succ = node;
        predecessorSuccessor( node->left, pred, succ, key );
    } else {
        pred = node;
        predecessorSuccessor( node->right, pred, succ, key );
    }
}

int main()
{
    Node * root = nullptr;
    int key = 20;
    for ( int i = 0; i < 10; ++i) {
        insert( root, algo::random_range(10, 40));
    }

    Node *pred = nullptr, *succ = nullptr;
    //print the inorder of created tree
    std::cout << "Tree's inorder traversal:\n";
    inorder(root);
    std::cout << "Finding predecessor and successor of key " << key << " (if exists):\n";
    predecessorSuccessor(root, pred, succ, key);
    if (pred != nullptr ) {
        std::cout << "Predeccessor is " << pred->data << std::endl;
    } else {
        std::cout << "No predecessor\n";
    }
    if (succ != nullptr) {
        std::cout << "Successor is " << succ->data << std::endl;
    } else {
        std::cout << "No successor\n";
    }
    return 0;
}
