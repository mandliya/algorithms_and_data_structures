/*
 * C Program to Find Nth Node in the Inorder Traversal of a Tree
 */
 
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}newnode;
 
newnode *root;
static ctr;
 
void nthnode(newnode *root, int n, newnode **nthnode);
int main()
{
    newnode *temp;
    root=0;
 
    // Construct the tree
    add(19);
    add(20);
    add(11);
    inorder(root);
    // Get the pointer to the nth Inorder node
    nthinorder(root, 6, &temp);
    printf("\n[%d]\n", temp->value);
    return(0);
}
 
// Get the pointer to the nth inorder node in "nthnode"
void nthinorder(newnode *root, int n, newnode **nthnode)
{
    static whichnode;
    static found;
 
    if (!found)
    {
        if (root)
        {
            nthinorder(root->left, n , nthnode);
            if (++whichnode == n)
            {
                printf("\n Found %dth node\n", n);
                found = 1;
                *nthnode = root;
            }
            nthinorder(root->right, n , nthnode);
        }
    }
}
 
inorder(newnode *root)
{
}
// Add value to a Binary Search Tree
add(int value)
{
    newnode *temp, *prev, *cur;
 
    temp = malloc(sizeof(newnode));
    temp->value = value;
    temp->left  = 0;
    temp->right = 0;
    if (root == 0)
    {
        root = temp;
    }
    else
    {
        prev = 0;
        cur = root;
        while(cur)
        {
            prev = cur;
            cur =(value < cur->value)? cur->left : cur->right;
        }
        if (value > prev->value)
            prev->right = temp;
        else
            prev->left  = temp;
    }
}
