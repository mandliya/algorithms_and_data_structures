// https : // practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/0/#

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {

        vector<int> ans;
        int max = a[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= max)
            {
                ans.push_back(a[i]);
                max = a[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};