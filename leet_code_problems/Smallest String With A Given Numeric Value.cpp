// https : // leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution
{
public:
    string getSmallestString(int n, int k)
    {

        string str(n, 'a');
        k -= n;

        while (k > 0)
        {
            str[--n] += min(25, k);
            k -= min(25, k);
        }

        return str;
    }
};