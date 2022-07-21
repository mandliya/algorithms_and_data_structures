// https : // leetcode.com/problems/excel-sheet-column-number/

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {

        int result = 0;

        for (auto ch : columnTitle)
        {
            int d = ch - 'A' + 1;
            result = result * 26 + d;
        }

        return result;
    }
};