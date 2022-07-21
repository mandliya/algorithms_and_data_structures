// https : // leetcode.com/problems/compare-version-numbers/

class Solution
{
public:
    int compareVersion(string v1, string v2)
    {

        int i = 0;
        int j = 0;

        int n1 = v1.size();
        int n2 = v2.size();

        int num1 = 0;
        int num2 = 0;

        while (i < n1 or j < n2)
        {
            while (i < n1 and v1[i] != '.')
            {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }

            while (j < n2 and v2[j] != '.')
            {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }

            if (num1 > num2)
            {
                return 1;
            }

            if (num1 < num2)
            {
                return -1;
            }

            i++;
            j++;

            num1 = 0;
            num2 = 0;
        }

        return 0;
    }
};