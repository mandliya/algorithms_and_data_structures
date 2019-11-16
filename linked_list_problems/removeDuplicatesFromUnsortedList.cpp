/**
 *  Given an unsorted linkedlist, remove duplicates from it.
 *  Input:  8->9->12->1->8->11->1->8->9->33
 *  Output: 8->9->12->1->11->33
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

Node *removeDuplicates(Node *head)
{
Node *curr = head, *temp = NULL;
while(curr != NULL)
{
temp = curr;
while(temp->next != NULL)
{
if(temp->next->data == curr->data)
temp->next = temp->next->next;
else
temp = temp->next;
}
curr = curr->next;
}
return head;
}

int main()
{
  Node * head = nullptr;
  // 8->9->12->1->8->11->1->8->9->33
  insert(head, 8);
  insert(head, 9);
  insert(head, 12);
  insert(head, 1);
  insert(head, 8);
  insert(head, 11);
  insert(head, 1);
  insert(head, 8);
  insert(head, 9);
  insert(head, 33);
  printList(head);

  Node *duplicateremovedlist=removeDuplicates(head);
  printList(duplicateremovedlist);
  return 0;
}
