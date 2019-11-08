#include<iostream>
#include<stack>

using namespace std;
struct node{
        int data;
        node* next;
};
void reverse(){
    if(head == NULL) return;
    stack <struct node*> S;
    node* temp = head;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(){
    struct node* head = NULL;
    reverse();   



    return 0;
}