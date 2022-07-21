// https : // practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> ans;

        if (arr.empty())
        {
            return ans;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int low = j + 1;
                int high = arr.size() - 1;
                int sum = k - arr[i] - arr[j];

                while (low < high)
                {
                    int add = arr[low] + arr[high];

                    if (sum > add)
                    {
                        low++;
                    }
                    else if (sum < add)
                    {
                        high--;
                    }
                    else
                    {
                        ans.push_back({arr[i], arr[j], arr[low], arr[high]});

                        while (low < high and arr[low] == arr[low + 1])
                        {
                            low++;
                        }

                        while (low < high and arr[high] == arr[high - 1])
                        {
                            high--;
                        }

                        low++;
                        high--;
                    }
                }

                while (j + 1 < arr.size() and arr[j] == arr[j + 1])
                {
                    j++;
                }
            }

            while (i + 1 < arr.size() and arr[i] == arr[i + 1])
            {
                i++;
            }
        }

        return ans;
    }
};