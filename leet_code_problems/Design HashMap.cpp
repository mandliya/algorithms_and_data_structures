// https://leetcode.com/problems/design-hashmap/

class MyHashMap
{
public:
    int arr[1000001];

    MyHashMap()
    {

        fill(arr, arr + 1000000, -1);
    }

    void put(int key, int value)
    {
        arr[key] = value;
    }

    int get(int key)
    {

        return arr[key];
    }

    void remove(int key)
    {

        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */