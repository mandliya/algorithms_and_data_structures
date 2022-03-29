class Solution
{
public:
    string capitalizeTitle(string title)
    {

        string result = "";
        vector<string> v;
        stringstream ss(title);
        string temp;
        while (getline(ss, temp, ' '))
        {
            v.push_back(temp);
        }

        for (auto word : v)
        {
            if (word.size() <= 2)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    word[i] = tolower(word[i]);
                }
            }
            else
            {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.size(); i++)
                {
                    word[i] = tolower(word[i]);
                }
            }
            result = result + word + " ";
        }
        result.pop_back();
        return result;
    }
};