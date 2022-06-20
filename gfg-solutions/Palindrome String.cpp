// https : // practice.geeksforgeeks.org/problems/palindrome-string0817/0/#

class Solution
{
public:
    int isPalindrome(string S)
    {
        int s = 0;
        int e = S.length() - 1;

        while (s <= e)
        {
            if (S[s] != S[e])
            {
                return 0;
            }

            s++;
            e--;
        }

        return 1;
    }
};