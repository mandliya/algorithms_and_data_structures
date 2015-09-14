/**
 *  Given a sorted linkedlist remove duplicates from it.
 *  5->5->5->7->7->9->11->13->13->15->15
 *  5->7->9->11->13->15
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data )
{
  Node * newNode = new Node(data);
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

void removeDuplicates ( Node * head )
{
  if ( !head || (head && !(head->next))) {
    return;
  }
  Node * currNode = head;
  Node * nextNode = nullptr;
  while( currNode ) {
    nextNode = currNode->next;
    while(nextNode && nextNode->data == currNode->data) {
      nextNode = nextNode->next;
    }
    currNode->next = nextNode;
    currNode = nextNode;
  }
}

int main()
{
  Node * head = nullptr;
  // 5->5->5->7->7->9->11->13->13->13->15->15
  insert(head, 5);
  insert(head, 5);
  insert(head, 5);
  insert(head, 7);
  insert(head, 7);
  insert(head, 9);
  insert(head, 11);
  insert(head, 13);
  insert(head, 13);
  insert(head, 13);
  insert(head, 13);
  insert(head, 15);
  insert(head, 15);
  printList(head);

  removeDuplicates(head);
  printList(head);
  return 0;
}
