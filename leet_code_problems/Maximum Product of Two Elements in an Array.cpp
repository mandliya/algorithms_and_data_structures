// https : // leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        priority_queue<int> pq;

        for (auto i : nums)
        {
            pq.push(i);
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        return (first - 1) * (second - 1);
    }
};