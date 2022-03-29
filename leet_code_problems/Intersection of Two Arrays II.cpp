// https : // leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_map<int, int> m;

        for (auto i : nums1)
        {
            m[i]++;
        }

        int n = nums2.size();
        vector<int> result;

        for (int j = 0; j < n; j++)
        {
            auto it = m.find(nums2[j]);
            if (it != m.end() and it->second > 0)
            {
                result.push_back(nums2[j]);
                it->second--;
            }
        }

        return result;
    }
};