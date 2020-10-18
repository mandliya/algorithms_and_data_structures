#include<iostream>
#include<stack>

using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
};
node *newnode(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

bool ismirror(node *root1,node *root2)
{
	if(!root1 && !root2)
	{
		return 1;
	}
	else if(!root1|| !root2)
	{
		return 0;
	}

	return (root1->data==root2->data)&&ismirror(root1->left,root2->right)&&ismirror(root1->right,root2->left);
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	
	node *b=newnode(1);
	b->left = newnode(3); 
    b->right = newnode(2); 
    b->right->left = newnode(5); 
    b->right->right = newnode(4);
	//preorder(root);
	cout<<ismirror(root,b);

	//preorder(root);
	
}
