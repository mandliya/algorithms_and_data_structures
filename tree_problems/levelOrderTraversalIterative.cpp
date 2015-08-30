/*
 * Program to implement level order traversal - iterative version
 */
#include <iostream>
#include <queue.h>


const int maxNodes = 15;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
 * An helper function to get a new node
 */

Node* newNode( int data )
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

/*
 * function to insert a new node.
 * Arg : root Node, new data
 */

void insert( Node* & node, int data)
{
    if ( node == nullptr) 
    {
        node = newNode(data);
    } 
    else
    {
        if (data < node->data) 
        {
            insert( node->left, data);
        }
        else
        {
            insert( node->right, data);
        }
    }
}

/*
 * Level order traversal
 */
void levelOrder( Node * node )
{
    std::cout << "Printing level order traversal of the tree:\n";
    if ( node == nullptr )
    {
        std::cout << "Empty tree\n";
        return ;
    }

    algo::Queue<Node*> Q(maxNodes);
    Q.push(node);
    while ( !Q.empty() )
    {
        Node *currNode = Q.front();
        std::cout << currNode->data << " ";
        Q.pop();
        if (currNode->left != nullptr)
        {
            Q.push(currNode->left);
        }
        if (currNode->right != nullptr)
        {
            Q.push(currNode->right);
        }
    }
    std::cout << std::endl;
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
