IN AntiClockWise



/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printleft(Node *root)
{
    while(root)
    {
    while(root->left)
    {
        cout<<root->data<<" ";
        root=root->left;
    }
        if(root->right)
        {
            cout<<root->data<<" ";
            
        }
        root=root->right;    
    
    }
}

void printleaf(Node *root)
{
    if(!root)
        return;
        
    printleaf(root->left);
    if(!root->left && !root->right)
        cout<<root->data<<" ";
    printleaf(root->right);
    
}

void printright(Node *root)
{
    if(!root)
        return;
    if(root->right)
    {
        printright(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printright(root->left);
        cout<<root->data<<" ";
    }
}

void printBoundary(Node *root)
{
     if(!root)
        return ;
        
    cout<<root->data<<" ";
    
    printleft(root->left);
    printleaf(root);
    printright(root->right);
     
}

int main()
{
	printBundary(root);
}
