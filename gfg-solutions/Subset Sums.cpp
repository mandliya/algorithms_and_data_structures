// https : // practice.geeksforgeeks.org/problems/subset-sums2234/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void genSubsets(vector<int> &arr, vector<int> &ans, int N, int sum, int idx)
    {
        if (N == idx)
        {
            ans.push_back(sum);
            return;
        }

        genSubsets(arr, ans, N, sum + arr[idx], idx + 1);
        genSubsets(arr, ans, N, sum, idx + 1);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum = 0;
        vector<int> ans;
        int idx = 0;

        genSubsets(arr, ans, N, sum, idx);

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends