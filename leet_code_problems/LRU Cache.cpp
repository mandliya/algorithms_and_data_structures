// https : // leetcode.com/problems/lru-cache/

class LRUCache
{
public:
    class ListNode
    {
    public:
        int key;
        int val;
        ListNode *prev;
        ListNode *next;

        ListNode(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    ListNode *head = new ListNode(-1, -1);
    ListNode *tail = new ListNode(-1, -1);

    int capacity;
    unordered_map<int, ListNode *> m;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(ListNode *dummy)
    {
        ListNode *temp = head->next;
        head->next = dummy;
        temp->prev = dummy;
        dummy->next = temp;
        dummy->prev = head;
    }

    void deleteNode(ListNode *dummy)
    {
        ListNode *dummyNext = dummy->next;
        ListNode *dummyPrev = dummy->prev;
        dummyPrev->next = dummyNext;
        dummyNext->prev = dummyPrev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            ListNode *node = m[key];
            int n = node->val;
            m.erase(key);
            deleteNode(node);
            addNode(node);
            m[key] = head->next;
            return n;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            ListNode *tmp = m[key];
            m.erase(key);
            deleteNode(tmp);
        }
        else if (m.size() == capacity)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new ListNode(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */