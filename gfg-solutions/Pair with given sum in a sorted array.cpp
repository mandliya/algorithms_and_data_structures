// https : // practice.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1#

class Solution
{
public:
    int Countpair(int arr[], int n, int sum)
    {
        int cnt = 0;

        int i = 0, j = n - 1;

        while (i < j)
        {
            if (arr[i] + arr[j] == sum)
            {
                cnt++;
                i++;
                j--;
            }
            else if (arr[i] + arr[j] < sum)
                i++;
            else
                j--;
        }

        return cnt ? cnt : -1;
    }
};