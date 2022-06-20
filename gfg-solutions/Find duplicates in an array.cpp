// https : // practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/0/#

class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {

        unordered_map<int, int> m;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        for (auto i : m)
        {
            if (i.second > 1)
            {
                ans.push_back(i.first);
            }
        }

        if (ans.size() == 0)
        {
            ans.push_back(-1);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};