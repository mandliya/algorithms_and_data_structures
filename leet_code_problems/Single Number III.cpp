// https : // leetcode.com/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorr = 0, set_bit = 0, xor1 = 0, xor2 = 0;
        for (auto num : nums)
            xorr = xorr ^ num;
        while (xorr)
        {
            if (xorr & 1)
                break;
            set_bit++;
            xorr = xorr >> 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << set_bit))
                xor1 = xor1 ^ nums[i];
            else
                xor2 = xor2 ^ nums[i];
        }

        return {xor1, xor2};
    }
};