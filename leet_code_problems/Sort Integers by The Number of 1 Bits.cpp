// https : // leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        multimap<int, int> mpp;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i], cnt = 0;
            while (x)
            {
                if (x & 1)
                    cnt++;
                x = x >> 1;
            }

            mpp.insert(pair<int, int>(cnt, arr[i]));
        }

        vector<int> ans;
        for (auto it : mpp)
            ans.emplace_back(it.second);
        return ans;
    }
};