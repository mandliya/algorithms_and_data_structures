// https: // leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;

        int windowLength = 0;
        int maxLength = 0;

        unordered_map<char, int> m;

        while (j < s.length())
        {
            char ch = s[j];

            if (m.count(ch) and m[ch] >= i)
            {
                i = m[ch] + 1;
                windowLength = j - i;
            }

            m[ch] = j;
            windowLength++;
            j++;

            if (windowLength > maxLength)
            {
                maxLength = windowLength;
            }
        }
        return maxLength;
    }
};