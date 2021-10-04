/**
 *  Problem: Only given a pointer to node of the linked list, delete the node.
 */
#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data )
{
  Node *newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while ( temp->next != nullptr ) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

void deleteNode( Node * node )
{
  // return if node is null
  if ( node == nullptr ) {
    return;
  }

  //this method won't work if we are given last node
  if ( node->next == nullptr ) {
    return;
  }

  Node * nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}

//Delete a Linked List node at a given position
void deleteNode(Node **head_ref, int position)
{
     
    // If linked list is empty
    if (*head_ref == NULL)
        return;
     
    // Store head node
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
         
        // Change head
        *head_ref = temp->next;
         
        // Free old head
        free(temp);            
        return;
    }
 
    // Find previous node of the node to be deleted
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     Node *next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
     
     
    temp->next = next;
}
 



int main()
{
  Node * head = nullptr;
  insert( head, 1 );
  insert( head, 12 );
  insert( head, 2 );
  insert( head, 3 );
  insert( head, 4 );
  printList( head );
  std::cout << "Deleting node with data 12 \n";
  deleteNode( head->next );
  printList( head );
  return 0;
}
