// https : // leetcode.com/problems/length-of-last-word/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        stringstream ss(s);
        string tmp = "";

        vector<string> res;

        while (getline(ss, tmp, ' '))
        {
            res.push_back(tmp);
        }

        string word;

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != "")
            {
                word = res[i];
            }
        }

        return word.size();
    }
};