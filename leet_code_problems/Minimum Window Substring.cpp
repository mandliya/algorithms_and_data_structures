// https : // leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int FS[256] = {0};
        int FP[256] = {0};
        int cnt = 0;
        int start = 0;
        int windowLength = 0;
        int minLength = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < t.length(); i++)
        {
            FP[t[i]]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            FS[ch]++;

            if (FP[ch] != 0 and FS[ch] <= FP[ch])
            {
                cnt++;
            }

            if (cnt == t.length())
            {
                while (FS[s[start]] == 0 or FS[s[start]] > FP[s[start]])
                {
                    FS[s[start]]--;
                    start++;
                }
                windowLength = i - start + 1;
                if (minLength > windowLength)
                {
                    minLength = windowLength;
                    startIndex = start;
                }
            }
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};