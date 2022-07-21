// https : // practice.geeksforgeeks.org/problems/binary-search/1#

class Solution
{
public:
    int binarysearch(int arr[], int n, int k)
    {

        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] == k)
            {
                return mid;
            }
            else if (arr[mid] > k)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return -1;
    }
};