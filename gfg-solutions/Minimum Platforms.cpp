// https : // practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 1, j = 0;
        int platforms = 1;
        int min_platforms = 1;

        while (i < n and j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else if (arr[i] > dep[j])
            {
                platforms--;
                j++;
            }

            min_platforms = max(min_platforms, platforms);
        }

        return min_platforms;
    }
};
