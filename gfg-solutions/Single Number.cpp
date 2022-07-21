// https : // practice.geeksforgeeks.org/problems/single-number1014/1

class Solution
{
public:
    int getSingle(int arr[], int n)
    {
        int xorr = 0;
        for (int i = 0; i < n; i++)
            xorr ^= arr[i];
        return xorr;
    }
};