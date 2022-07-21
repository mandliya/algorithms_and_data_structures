// https : // leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        priority_queue<int> pq;

        for (auto i : stones)
        {
            pq.push(i);
        }

        while (true)
        {
            if (pq.empty())
            {
                return 0;
            }

            if (pq.size() == 1)
            {
                return pq.top();
            }

            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();

            if (f != s)
            {
                pq.push(f - s);
            }
        }
    }
};