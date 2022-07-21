// https : // leetcode.com/problems/the-latest-time-to-catch-a-bus/

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size(), m = passengers.size(), j = 0;
        set<int> st(passengers.begin(), passengers.end());
        bool is_full = false;

        for (int i = 0; i < n; i++)
        {
            int curr_capacity = 0;
            while (j < m and passengers[j] <= buses[i] and curr_capacity < capacity)
                j++, curr_capacity++;
            is_full = curr_capacity == capacity ? true : false;
        }

        int x;
        if (is_full)
            x = passengers[j - 1];
        else
            x = buses[n - 1];

        while (st.find(x) != st.end())
            x--;

        return x;
    }
};