class Solution
{
public:
    vector<int> kClosest(vector<int> &arr, int k, int x, vector<int> &ans)
    {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            pq.push({abs(x - arr[i]), arr[i]});

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

        sort(ans.begin(), ans.end());

        return ans;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        vector<int> ans;

        kClosest(arr, k, x, ans);

        return ans;
    }
};