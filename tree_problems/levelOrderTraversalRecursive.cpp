/*
 * Level order BST traveral iterative
 */
#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode( int data )
{   
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void insert( Node* & node, int data)
{
    if ( node == nullptr)
    {
        node = newNode(data);
    }
    else
    {
        if ( data < node->data )
        {
            insert(node->left, data);
        } 
        else
        {
            insert(node->right, data);
        }
    }
}

int height( const Node * node) 
{
    if ( node == nullptr )
    {
        return 0;
    }
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return ( 1  + ((leftHeight > rightHeight) ? leftHeight : rightHeight));
    }
}

void printLevel(Node *node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    if ( level == 1 )
    {
        std::cout << node->data <<" ";
    } 
    else
    {
        printLevel( node->left, level - 1);
        printLevel( node->right, level - 1);
    }

}


void levelOrder( Node * node )
{
    std::cout << "Level order traversal of the tree:\n";
    int h = height(node);
    for ( int i = 1; i <= h; ++i ) {
        printLevel(node, i );
        std::cout << std::endl;
    }
}

int main()
{
    Node * root;
    insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    levelOrder(root);
    return 0;
}

