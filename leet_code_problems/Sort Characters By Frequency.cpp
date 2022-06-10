// https : // leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string freqSort(string s)
    {
        priority_queue<pair<int, char>> pq;

        unordered_map<char, int> m;

        for (auto i : s)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            pq.push({i.second, i.first});
        }

        string ans;

        while (!pq.empty())
        {
            int n = pq.top().first;
            char ch = pq.top().second;

            while (n > 0)
            {
                ans += ch;
                n--;
            }

            pq.pop();
        }

        return ans;
    }

    string frequencySort(string s)
    {

        string ans = freqSort(s);

        return ans;
    }
};