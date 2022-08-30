class Solution {
private:
    void sol(string digits, string output, int index, vector<string>& ans, string map[]){
        
        // base case
        if (index > digits.length()) return;
        
        if (index == digits.length()) {
            ans.push_back(output);
            return;
        }
        
        // If we dont subtract 0, then output will be given as a char since digits is a string
        // But we need number in int --> so subtract 0
        int number = digits[index] - '0';
        string value = map[number];
        
        for (int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            sol(digits, output, index + 1, ans, map);
            
            // backtracking the changes made
            output.pop_back();
        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        
        vector <string> ans;
        string output;
        int index = 0;
        
        // In case of empty string --> output will also be an empty arr
        if (digits.length() == 0) return ans;
        
        // Mapping index with corresponding strings
        string map[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        sol(digits, output, index, ans, map);
        
        return ans;
    }
        
};
