// https : // leetcode.com/problems/fizz-buzz/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> v;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                v.push_back("FizzBuzz");
            }
            else if (i % 5 == 0)
            {
                v.push_back("Buzz");
            }
            else if (i % 3 == 0)
            {
                v.push_back("Fizz");
            }
            else
            {
                string m = to_string(i);
                v.push_back(m);
            }
        }
        return v;
    }
};