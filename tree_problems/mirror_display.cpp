
void Bst :: mirror(Node *root){
Node *temp;

if(root!=NULL){
temp = root->left;
root->left = root->right;
root->right=temp;
mirror(root->left);
mirror(root->right);
}

}

void Bst :: displayMirror(){
mirror(root);
cout<<"\nLevel Wise display Of Mirror tree: "<<endl;
levelWise(root);
cout<<endl;

}

void Bst:: levelWise(Node *r){

queue <Node *> q;
Node *temp;
temp=r;
q.push(temp);
cout<<"Word"<<"\tMeaning"<<"\n";
while(q.empty()!=1)
{
temp=q.front();
q.pop();
cout<<temp->key<<" : \t"<<temp->value<<"\n";
if(temp->left!=NULL)
{
q.push(temp->left);
}
if(temp->right!=NULL)
{
q.push(temp->right);
}
}
}
