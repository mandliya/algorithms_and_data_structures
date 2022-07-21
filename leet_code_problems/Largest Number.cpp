// https : // leetcode.com/problems/largest-number/

class Solution
{
public:
    bool static comparator(string a, string b)
    {
        return a + b > b + a;
    }

    string largestNumber(vector<int> &nums)
    {
        string s = "";

        vector<string> v;
        for (auto i : nums)
        {
            v.push_back(to_string(i));
        }

        sort(v.begin(), v.end(), comparator);

        for (auto x : v)
        {
            s += x;
        }

        return s[0] == '0' ? "0" : s;
    }
};