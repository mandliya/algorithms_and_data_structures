// https : // practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

// BRUTE FORCE
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {

        vector<int> ans(n + m);
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            ans[k] = arr1[i];
            k++;
        }

        for (int i = 0; i < m; i++)
        {
            ans[k] = arr2[i];
            k++;
        }

        sort(ans.begin(), ans.end());
        k = 0;

        for (int i = 0; i < n; i++)
        {
            arr1[i] = ans[k];
            k++;
        }

        for (int i = 0; i < m; i++)
        {
            arr2[i] = ans[k];
            k++;
        }
    }
};