#include<iostream>
#include<queue>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}
int diameter(node *root,int *ans)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=diameter(root->left,ans);
	int rh=diameter(root->right,ans);
	
	*ans=max(*ans,lh+rh+1);
	
	return 1+max(lh,rh);
}
int main()
{

	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(10);
	root->right->right=newnode(90);
//	printlevel(root);
	int ans=0;
	diameter(root,&ans);
	cout<<ans;
}
