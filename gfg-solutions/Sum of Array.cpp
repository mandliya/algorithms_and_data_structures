// https : // practice.geeksforgeeks.org/problems/sum-of-array2326/1

class Solution
{
public:
    // function to return sum of elements
    // in an array of size n
    int add = 0;
    int i = 0;
    int sum(int arr[], int n)
    {
        while (i < n)
        {
            add = add + arr[i];
            i++;
        }
        return add;
    }
};