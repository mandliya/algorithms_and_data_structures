// https : // practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1/?page=1&category[]=Heap&sortBy=submissions#

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        long long int min_cost = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

        for (int i = 0; i < n; i++)
            pq.push(arr[i]);

        while (pq.size() >= 2)
        {
            long long int cost_1 = pq.top();
            pq.pop();

            long long int cost_2 = pq.top();
            pq.pop();

            pq.push(cost_1 + cost_2);

            min_cost += cost_1 + cost_2;
        }

        return min_cost;
    }
};
