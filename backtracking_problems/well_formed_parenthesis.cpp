class Solution {
public:
    bool isValid(string &s)
    {
        int open = 0;
        for (const char &c:s)
        {
            if (c=='(') open++;
            else open--;
            if (open < 0)
                return false;
        }
        return open==0;
    }
    
    void findValid(int n, string curr, vector<string> &res, int open, int close)
    {
        if (curr.size() == n*2)
        {
            //if (isValid(curr))
                res.push_back(curr);
            return;
        }
        
        if (open < n){
            findValid(n, curr + '(', res, open+1, close);
        }
        
        if (close < open){
            findValid(n, curr + ')', res, open, close+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";
        findValid(n, curr, res, 0, 0);
        return res;
    }
};
