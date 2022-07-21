// https : // practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/0/?page=1&category[]=Linked%20List&curated[]=1&sortBy=submissions#

int intersectPoint(Node *head1, Node *head2)
{
    Node *a = head1;
    Node *b = head2;

    while (a != b)
    {
        a = a == NULL ? head2 : a->next;
        b = b == NULL ? head1 : b->next;
    }

    return b->data;
}