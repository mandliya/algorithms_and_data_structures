// https : // practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

class Solution
{
public:
    bool find3Numbers(int A[], int n, int X)
    {
        vector<vector<int>> ans;

        if (n == 0)
        {
            return false;
        }

        sort(A, A + n);

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 or (i > 0 and A[i] != A[i - 1]))
            {
                int low = i + 1;
                int high = n - 1;
                int sum = X - A[i];

                while (low < high)
                {
                    int add = A[low] + A[high];

                    if (sum == add)
                    {
                        ans.push_back({A[i], A[low], A[high]});

                        while (low < high and A[low] == A[low + 1])
                        {
                            low++;
                        }

                        while (low < high and A[high] == A[high - 1])
                        {
                            high--;
                        }

                        low++;
                        high--;
                    }
                    else if (sum > add)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }

        return !ans.empty();
    }
};