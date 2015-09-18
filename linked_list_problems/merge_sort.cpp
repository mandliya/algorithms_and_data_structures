#include <iostream>

struct Node {
  int data;
  Node * next;
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

void printList( Node * head ) {
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

void push( Node * & head, int data )
{
  Node * newNode = new Node(data);
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

void splitList( Node * head, Node * & list1, Node * & list2 )
{
  if ( head == nullptr || head->next == nullptr ) {
    list1 = head;
    list2 = nullptr;
    return;
  }
  Node * fast = head->next;
  Node * slow = head;
  while( fast ) {
    fast = fast->next;
    if( fast ) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  list1 = head;
  list2 = slow->next;
  slow->next = nullptr;
}


void moveNode( Node * & dstNode, Node * & srcNode )
{
  if (srcNode == nullptr) {
    return;
  }
  Node * nextNode = srcNode->next;
  dstNode->next = srcNode;
  dstNode = srcNode;
  srcNode = nextNode;
}


Node * sortedMerge(Node * list1, Node * list2)
{
  if (list1 == nullptr) {
    return list2;
  }

  if (list2 == nullptr) {
    return list1;
  }

  Node dummy(0);
  Node * tailNode = &dummy;
  dummy.next = nullptr;

  while( list1 && list2 ) {
    if (list1->data <= list2->data){
      moveNode(tailNode, list1);
    } else {
      moveNode(tailNode, list2);
    }
  }
  while(list2) {
    moveNode(tailNode, list2);
  }
  while(list1) {
    moveNode(tailNode, list1);
  }
  return (dummy.next);
}

void mergeSort( Node * & head ) {
  if (head == nullptr || head->next == nullptr) {
    return;
  }
  Node * list1 = nullptr;
  Node * list2 = nullptr;
  splitList(head, list1, list2);
  mergeSort(list1);
  mergeSort(list2);
  head = sortedMerge(list1, list2);
}

int main()
{
  Node * head = nullptr;
  push(head, 5);
  push(head, 1);
  push(head, 3);
  push(head, 6);
  push(head, 4);
  push(head, 2);
  std::cout << "Before Sorting :";
  printList(head);
  mergeSort(head);
  std::cout << "After Sorting  :";
  printList(head);
  return 1;
}
