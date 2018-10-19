#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node* prev;
  node* next;	
};	

node * head;

void add(int x)
{
  node * temp = new node();
  
  if(head!=NULL)
  head->prev = temp;
  
  temp->next = head;
  temp->data = x;
  temp->prev = NULL;
  
  head = temp;
  	
}

void print()
{
	node * temp1 = head;
	
	while(temp1!=NULL)
	{
		cout << temp1->data << endl;
		temp1=temp1->next;
	}
	
}

void Delete(int n)
{
	
	if(n==1)
	{
		head = head->next;
	}
	
	else
	{
	
  node * t2 = head;
  
  for(int i=0;i<n-1;i++)
  {
  	t2=t2->next;	
  }	
  
	(t2->prev)->next = t2->next;
}


}

int main()
{
	head = NULL;
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(6);
	print();
	
	cout << " Enter number to delete" << endl;
	int n ;
	cin >> n;
	Delete(n);
	print();
}
