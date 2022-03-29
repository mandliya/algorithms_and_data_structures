// https: // leetcode.com/problems/first-unique-character-in-a-string/

class Solution
{
public:
    int firstUniqChar(string s)
    {

        unordered_map<char, int> m;

        for (auto ch : s)
        {
            m[ch]++;
        }

        bool is_there = false;
        char c;

        for (auto i : m)
        {
            if (i.second == 1)
            {
                is_there = true;
                c = i.first;
            }
        }

        for (int x = 0; x < s.length(); x++)
        {
            if (c == s[x])
            {
                return x;
            }
        }

        return -1;
    }
};