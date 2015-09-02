/*
 * Print a level order zig-zag traversal.
 *
 */


#include<iostream>

template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
};


template <typename T>
Node<T> * newNode( T data )
{
    Node<T> * temp = new Node<T>;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

template <typename T>
void insert( Node<T>* & node, T data)
{
    if ( node == nullptr )
    {
        node = newNode( data );        
    }
    else
    {
        if ( data < node->data )
        {
            insert( node->left, data );
        }
        else
        {
            insert( node->right, data);
        }
    }
}

template <typename T>
void printLevel( Node<T> * node, int level, bool zig )
{
    if ( node == nullptr ) {
        return;
    }

    if ( level == 1 ) {
        std::cout << node->data << " ";
    }
    else {
        if( zig ){
            printLevel( node->left, level - 1,  zig );
            printLevel( node->right, level - 1, zig );
        } else {
            printLevel( node->right, level - 1, zig );
            printLevel( node->left, level - 1,  zig );
        }
    }
}

template <typename T>
int height ( Node<T> * node )
{
    if ( node == nullptr ) {
        return 0;
    }
    int lheight = height( node->left );
    int rheight = height( node->right );
    return ( 1 + (( lheight > rheight ) ? lheight : rheight));
}

template <typename T>
void levelOrderTraversal( Node<T> *root )
{
    int h = height(root);
    bool zig = true;
    for ( int i = 1; i <= h; ++i ) {
        printLevel( root, i, zig );
        std::cout << std::endl;
        zig = !zig;
    }
}


template <typename T>
void inorder( Node<T> * node )
{
    if ( node != nullptr ) {
        inorder( node->left );
        std::cout << node->data << " " ; 
        inorder( node->right );
    }
}

int main()
{
    Node<int> *root;
    insert( root, 11 );
    insert( root, 9 );
    insert( root, 20 );
    insert( root, 15 );
    insert( root, 25 );
    std::cout << "Inorder:";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Level order: \n";
    levelOrderTraversal( root );
    return 0;
}



