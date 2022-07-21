// https : // leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution
{
public:
    class compare_fun
    {
    public:
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    vector<int> freqSort(vector<int> &nums, vector<int> &ans)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare_fun> pq;

        map<int, int> m;

        for (auto i : nums)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            pq.push({i.second, i.first});
        }

        while (!pq.empty())
        {
            int freq = pq.top().first;
            int element = pq.top().second;

            for (int i = 0; i < freq; i++)
            {
                ans.push_back(element);
            }

            pq.pop();
        }

        return ans;
    }

    vector<int> frequencySort(vector<int> &nums)
    {

        vector<int> ans;

        freqSort(nums, ans);

        return ans;
    }
};