// https : // practice.geeksforgeeks.org/problems/majority-element-1587115620/0/#

class Solution
{
public:
    int majorityElement(int arr[], int size)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < size; i++)
        {
            m[arr[i]]++;
        }

        for (auto i : m)
        {
            if (i.second > size / 2)
            {
                return i.first;
            }
        }

        return -1;
    }
};