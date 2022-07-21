// https : // leetcode.com/problems/remove-k-digits/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        int n = num.length();

        if (k == 0)
        {
            return num;
        }

        if (n <= k)
        {
            return "0";
        }

        string result = "";
        stack<char> s;

        for (int i = 0; i < n; i++)
        {
            while (k > 0 and !s.empty() and num[i] < s.top())
            {
                s.pop();
                k--;
            }

            s.push(num[i]);

            if (s.size() == 1 and num[i] == '0')
            {
                s.pop();
            }
        }

        while (k > 0 and !s.empty())
        {
            k--;
            s.pop();
        }

        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }

        reverse(result.begin(), result.end());

        if (result.length() == 0)
        {
            return "0";
        }

        return result;
    }
};