// https : // practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

class Solution
{
public:
    long long int count = 0;

    void merge(long long arr[], long long l, long long mid, long long r)
    {
        long long int i = l;
        long long int j = mid + 1;
        long long int k = l;
        long long int B[r + 1];

        while (i <= mid && j <= r)
        {
            if (arr[i] > arr[j])
            {
                count += mid - i + 1;
                B[k++] = arr[j++];
            }
            else
                B[k++] = arr[i++];
        }

        while (i <= mid)
        {
            B[k++] = arr[i++];
        }
        while (j <= r)
        {
            B[k++] = arr[j++];
        }

        for (int k = l; k <= r; k++)
        {
            arr[k] = B[k];
        }
    }

    void mergeSort(long long arr[], long long l, long long r)
    {

        if (l >= r)
            return;

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);

        return;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N - 1);
        return count;
    }
};