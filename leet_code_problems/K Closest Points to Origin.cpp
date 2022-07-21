// https : // leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    vector<vector<int>> kClosePoints(vector<vector<int>> &points, int k, vector<vector<int>> &ans)
    {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y; // no need to find sqrt.

            pq.push({dist, {x, y}});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            vector<int> tmp;
            tmp.push_back(pq.top().second.first);
            tmp.push_back(pq.top().second.second);
            ans.push_back(tmp);

            pq.pop();
        }

        return ans;
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        vector<vector<int>> ans;

        kClosePoints(points, k, ans);

        return ans;
    }
};