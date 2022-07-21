// https : // practice.geeksforgeeks.org/problems/subset-sums2234/1#

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
