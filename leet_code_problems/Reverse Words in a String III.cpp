// https : // leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {

        vector<string> v;
        stringstream ss(s);

        string temp;

        while (getline(ss, temp, ' '))
        {
            v.push_back(temp);
        }

        for (int i = 0; i < v.size(); i++)
        {
            reverse(v[i].begin(), v[i].end());
        }

        string res = "";

        for (auto x : v)
        {
            res += x + " ";
        }

        res.pop_back();

        return res;
    }
};