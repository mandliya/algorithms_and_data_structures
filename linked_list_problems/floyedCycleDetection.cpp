/**
 *  Problem : Using Floyd's cycle finding algorithm, detect if a linkedlist
 *  contain cycle, if it does contain cycle, remove the loop
 *  Visit : https://en.wikipedia.org/wiki/Cycle_detection
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void removeLoop( Node * loopNode, Node * head )
{
  Node * ptr1 = head;
  Node * ptr2 = loopNode;
  while ( ptr1->next != ptr2->next ) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  ptr2->next = nullptr;
}

bool detectAndRemoveCycle( Node * head )
{
  if ( head == nullptr) {
    return false;
  }
  Node * fastPtr = head;
  Node * slowPtr = head;
  while( slowPtr && fastPtr && fastPtr->next)
  {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
    if ( fastPtr == slowPtr ) {
      removeLoop( slowPtr, head );
      return true;
    }
  }
  return false;
}



void insert( Node * & head, int data )
{
  Node * newNode = new Node( data );
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while( temp->next != nullptr ) {
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


int main()
{
    Node * head = nullptr;
    insert( head , 1 );
    insert( head , 2 );
    insert( head , 3 );
    insert( head , 4 );
    insert( head , 5 );
    std::cout << "Current List:\n";
    printList( head );
    std::cout << "Inserting loop, connecting 5 to 2 \n";
    head->next->next->next->next->next = head->next;
    std::cout << "Detecting and deleting loop\n";
    detectAndRemoveCycle(head);
    std::cout << "Back to the same old list\n";
    printList( head );
    return 0;
}
