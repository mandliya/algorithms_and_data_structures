// https : // leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k, vector<int> &ans)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;

        for (auto i : nums)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            pq.push(make_pair(i.second, i.first));

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<int> ans;

        topK(nums, k, ans);

        return ans;
    }
};