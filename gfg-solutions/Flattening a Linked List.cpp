// https : // practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

Node *
mergeTwoLists(Node *list1, Node *list2)
{
    Node *temp = new Node(0);
    Node *dummy = temp;

    while (list1 != NULL and list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->bottom = list1;
            temp = temp->bottom;
            list1 = list1->bottom;
        }
        else
        {
            temp->bottom = list2;
            temp = temp->bottom;
            list2 = list2->bottom;
        }
    }

    if (list1 != NULL)
    {
        temp->bottom = list1;
    }
    else
    {
        temp->bottom = list2;
    }

    return dummy->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL or root->next == NULL)
    {
        return root;
    }

    root->next = flatten(root->next);

    root = mergeTwoLists(root, root->next);

    return root;
}