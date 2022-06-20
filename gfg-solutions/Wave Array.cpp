// https : // practice.geeksforgeeks.org/problems/wave-array-1587115621/0/#

class Solution
{
public:
    void convertToWave(int n, vector<int> &arr)
    {

        int i = 0;
        int j = 1;

        while (i < n and j < n)
        {
            swap(arr[i], arr[j]);

            i += 2;
            j += 2;
        }
    }
};