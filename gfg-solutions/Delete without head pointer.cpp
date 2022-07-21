// https : // practice.geeksforgeeks.org/problems/delete-without-head-pointer/0/?page=1&category[]=Linked%20List&curated[]=1&sortBy=submissions#

class Solution
{
public:
    void deleteNode(Node *del)
    {
        del->data = del->next->data;
        del->next = del->next->next;
    }
};