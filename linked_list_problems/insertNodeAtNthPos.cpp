// code to insert node at nth position in a linkedlist 
#include<iostream>

using namespace std;
struct node{
    int data;
    node* next;
};
struct node* head;

void insert(int data,int n){
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    node* temp2 = head;
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void print(){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
}
int main(){
    head = NULL;
    insert(2,1);
    insert(5,4);
    insert(4,3);
    insert(8,2);
    print();
}