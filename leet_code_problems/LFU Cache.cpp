// https : // leetcode.com/problems/lfu-cache/

struct Node
{
    int key;
    int value;
    int cnt;

    Node *prev;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        node->prev = head;
        size++;
    }

    void delNode(Node *node)
    {
        Node *nodeprev = node->prev;
        Node *nodenext = node->next;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;

    int capacity;
    int min_freq;
    int curr_size;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        min_freq = 0;
        curr_size = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->delNode(node);

        if (node->cnt == min_freq and freqListMap[node->cnt]->size == 0)
        {
            min_freq++;
        }

        List *nextHigherFreqList = new List();

        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);

            return val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curr_size == capacity)
            {
                List *list = freqListMap[min_freq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[min_freq]->delNode(list->tail->prev);
                curr_size--;
            }

            curr_size++;
            min_freq = 1;

            List *listFreq = new List();

            if (freqListMap.find(min_freq) != freqListMap.end())
            {
                listFreq = freqListMap[min_freq];
            }

            Node *node = new Node(key, value);
            listFreq->addNode(node);
            keyNode[key] = node;
            freqListMap[min_freq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */