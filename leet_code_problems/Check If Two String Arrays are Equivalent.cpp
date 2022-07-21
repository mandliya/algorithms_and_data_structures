// https : // leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {

        string str1 = "";
        string str2 = "";

        for (auto i : word1)
        {
            str1 += i;
        }

        for (auto j : word2)
        {
            str2 += j;
        }

        return str1 == str2;
    }
};