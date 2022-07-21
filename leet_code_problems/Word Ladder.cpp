// https: // leetcode.com/problems/word-ladder/

class Solution
{
public:
    int ladderLength(string s, string e, vector<string> &list)
    {
        unordered_set<string> dict; // to store the dict words;
        unordered_set<string> v;
        queue<pair<string, int>> q;

        for (string i : list)
        {
            dict.insert(i);
        }

        q.push({s, 1});
        v.insert(s);

        while (!q.empty())
        {
            pair<string, int> f = q.front();
            q.pop();
            string curr = f.first;

            if (curr == e)
            {
                return f.second;
            }

            for (int i = 0; i < curr.length(); i++)
            {
                char currchar = curr[i];
                for (int j = 0; j < 26; j++)
                {
                    curr[i] = 'a' + j; // only character is changed and then checked if the word is present in the dictionary or not

                    if (dict.find(curr) != dict.end() and v.find(curr) == v.end())
                    {
                        v.insert(curr);
                        q.push({curr, f.second + 1});
                    }
                }

                curr[i] = currchar; // restored back to the original string so that only the next index is now changed
            }
        }
        return 0;
    }
};