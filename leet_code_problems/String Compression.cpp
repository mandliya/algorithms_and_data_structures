// https : // leetcode.com/problems/string-compression/

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        int n = chars.size();
        int i = 0;
        int result = 0;

        while (i < n)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
            {
                j++;
            }

            chars[result++] = chars[i];
            int cnt = j - i;

            if (cnt > 1)
            {
                string strcnt = to_string(cnt);
                for (auto ch : strcnt)
                {
                    chars[result++] = ch;
                }
            }
            i = j;
        }
        return result;
    }
};