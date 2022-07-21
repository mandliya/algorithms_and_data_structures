// https: // leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> m;

    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
        {
            return head;
        }

        if (m.find(head) != m.end())
        {
            return m[head];
        }

        Node *node = new Node(head->val);
        m[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};

// SC: O(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        Node *iter = head;
        Node *front = head;

        while (iter != NULL)
        {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        iter = head;

        while (iter != NULL)
        {
            if (iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }

            iter = iter->next->next;
        }

        iter = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;

        while (iter != NULL)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }

        return dummy->next;
    }
};