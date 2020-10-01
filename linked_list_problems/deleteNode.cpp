/**
 *  Problem: Only given a pointer to node of the linked list, delete the node.
 */
#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
}*head=NULL;

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

void deleteNode( Node * node ) // works in every condition
{
  Node *p=head;
  Node *q=NULL;
  while(p!=node)
  {
      q=p;
      p=p->next;
  }
  q->next=p->next;
  p->next=NULL;
  delete p;







}

  Node * nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}

int main()
{

  insert( head, 1 );
  insert( head, 12 );
  insert( head, 2 );
  insert( head, 3 );
  insert( head, 4 );
    insert( head, 5 );
  printList( head );
  std::cout << "Deleting node with data 12 \n";
  deleteNode( head->next );
  printList( head );
  return 0;
}
