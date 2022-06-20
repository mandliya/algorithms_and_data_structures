// https : // practice.geeksforgeeks.org/problems/largest-element-in-array4009/1#

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int largest = -1;

        for (auto i : arr)
        {
            largest = max(i, largest);
        }

        return largest;
    }
};