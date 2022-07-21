// https : // leetcode.com/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {

        int i = a.length() - 1;
        int j = b.length() - 1;

        string ans = "";
        int carry = 0;

        while (i >= 0 or j >= 0)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum += a[i--] - '0';
            }

            if (j >= 0)
            {
                sum += b[j--] - '0';
            }

            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum % 2);
        }

        if (carry)
        {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};