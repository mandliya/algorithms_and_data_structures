// https : // leetcode.com/problems/to-lower-case/

class Solution
{
public:
    string toLowerCase(string s)
    {

        string str;
        for (auto i : s)
        {
            str += tolower(i);
        }

        return str;
    }
};