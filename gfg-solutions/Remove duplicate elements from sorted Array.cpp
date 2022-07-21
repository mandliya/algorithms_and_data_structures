// https : // practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1#

class Solution
{
public:
    int remove_duplicate(int arr[], int n)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        int j = 0;

        for (auto i : m)
        {
            arr[j] = i.first;
            j++;
        }

        sort(arr, arr + j);

        return j;
    }
};