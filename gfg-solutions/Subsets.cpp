// https : // practice.geeksforgeeks.org/problems/subsets-1613027340/0/?category#

class Solution
{
public:
    void generate_subsets(vector<int> &A, vector<int> &ds, vector<vector<int>> &subsets, int curr_idx, int n)
    {
        if (curr_idx >= n)
        {
            subsets.push_back(ds);
            return;
        }
        ds.push_back(A[curr_idx]);
        generate_subsets(A, ds, subsets, curr_idx + 1, n);
        ds.pop_back();
        generate_subsets(A, ds, subsets, curr_idx + 1, n);
    }

    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<int> ds;
        vector<vector<int>> subsets;
        int n = A.size();
        generate_subsets(A, ds, subsets, 0, n);
        sort(subsets.begin(), subsets.end());

        return subsets;
    }
};