// https : // practice.geeksforgeeks.org/problems/k-largest-elements3736/1#

class Solution
{
public:
    bool static comparator(int a, int b)
    {
        return a > b;
    }

    vector<int> kLargest(int arr[], int n, int k)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        sort(ans.begin(), ans.end(), comparator);

        return ans;
    }
};