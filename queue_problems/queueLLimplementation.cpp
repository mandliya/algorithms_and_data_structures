#include<iostream>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void Enqueue(int x){
    struct node* temp = new node();
    temp->data = x;
    temp->next = NULL;

    if((front==NULL)&&(rear==NULL)){
        rear=front=temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue(){
    struct node* temp = front;
    if(front==NULL){
        printf("Queue Already Empty");
        return;
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(6);
    Enqueue(7);
    Enqueue(9);
    Enqueue(8);
    Dequeue();
    struct node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
    return 0;
}
