// https : // leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {

        string s = to_string(abs(x));

        ::reverse(s.begin(), s.end());

        try
        {

            return x < 0 ? -(stoi(s)) : stoi(s);
        }

        catch (...)
        {
            return 0;
        }
    }
};