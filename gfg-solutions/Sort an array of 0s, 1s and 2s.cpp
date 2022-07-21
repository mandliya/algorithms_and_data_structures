// https : // practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (a[mid] == 0)
                swap(a[low++], a[mid++]);
            else if (a[mid] == 1)
                mid++;
            else
                swap(a[mid], a[high--]);
        }
    }
};