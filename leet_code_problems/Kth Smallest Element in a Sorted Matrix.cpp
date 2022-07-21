// https : // leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;
        for (auto i : matrix)
        {
            for (auto j : i)
            {
                pq.push(j);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};