// https : // leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {

        vector<vector<string>> ans;

        for (int i = 0; i < sentences.size(); i++)
        {
            stringstream ss(sentences[i]);
            string temp = "";
            vector<string> v;

            while (getline(ss, temp, ' '))
            {
                v.push_back(temp);
            }

            ans.push_back(v);
        }

        int mx = 0;

        for (int j = 0; j < ans.size(); j++)
        {
            int mx1 = ans[j].size();
            mx = max(mx, mx1);
        }

        return mx;
    }
};