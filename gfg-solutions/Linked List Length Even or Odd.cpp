// https : // practice.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1#

int isLengthEvenOrOdd(struct Node *head)
{
    int cnt = 1;

    struct Node *tmp = head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        cnt++;
    }

    return cnt % 2 != 0;
}