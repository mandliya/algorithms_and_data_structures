#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct Node* head;
void insertEnd(struct Node** head_ref,int x){
    struct Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    Node* ptr = *head_ref;
    if(head == NULL){
        head = temp;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void print(){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
}
int main(){
    struct Node* head = NULL; 
    insertEnd(&head,2);
    insertEnd(&head,4);
    print();
    return 0;
}