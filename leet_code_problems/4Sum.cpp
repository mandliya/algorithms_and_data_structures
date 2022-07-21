// https : // leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;

        if (nums.empty())
        {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int remaining_target = target - nums[i] - nums[j];
                int low = j + 1;
                int high = nums.size() - 1;

                while (low < high)
                {
                    int add = nums[low] + nums[high];

                    if (remaining_target > add)
                    {
                        low++;
                    }
                    else if (remaining_target < add)
                    {
                        high--;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});

                        while (low < high and nums[low] == nums[low + 1])
                        {
                            low++;
                        }

                        while (low < high and nums[high] == nums[high - 1])
                        {
                            high--;
                        }

                        low++;
                        high--;
                    }
                }

                while (j + 1 < nums.size() and nums[j] == nums[j + 1])
                {
                    j++;
                }
            }

            while (i + 1 < nums.size() and nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return ans;
    }
};