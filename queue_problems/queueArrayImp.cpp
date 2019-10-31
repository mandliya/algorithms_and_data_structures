//code for circular array queue implementation
#include<iostream>

using namespace std;
const int N = 10;
int A[N];
int front = (-1),rear = (-1);
bool IsEmpty();
void Enqueue(int x);
void Dequeue();

int main(){
    
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Dequeue();
    Dequeue();
    IsEmpty();
    int count = (rear+N-front)%N+1;
    for(int i=0;i<count;i++){

			int index = (front+i) % N; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
    cout<<front <<rear;
    return 0;
}


bool IsEmpty(){
    if(front==-1&&rear==-1){
        return true;
    }
    else return false;
}
void Enqueue(int x){
    if(((rear+1)%N)==front) 
        return;
    else if(IsEmpty()){
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%N;
    }
    A[rear]=x;
}
void Dequeue(){
    if(IsEmpty()){
        return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front = (front+1)%N;
     }
}
