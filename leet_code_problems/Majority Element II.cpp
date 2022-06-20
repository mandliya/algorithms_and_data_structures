// https : // leetcode.com/problems/majority-element-ii/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int cnt1 = 0;
        int cnt2 = 0;

        int element1 = -1;
        int element2 = -1;

        vector<int> ans;

        for (auto num : nums)
        {
            if (num == element1)
            {
                cnt1++;
            }
            else if (num == element2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                element1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                element2 = num;
                cnt2 = 1;
            }

            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;

        for (auto i : nums)
        {
            if (i == element1)
            {
                cnt1++;
            }

            else if (i == element2)
            {
                cnt2++;
            }
        }

        if (cnt1 > nums.size() / 3)
        {
            ans.push_back(element1);
        }

        if (cnt2 > nums.size() / 3)
        {
            ans.push_back(element2);
        }

        return ans;
    }
};