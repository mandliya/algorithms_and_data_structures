// https : // leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> indices;
        int i = 0, j = numbers.size() - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                indices.push_back(i + 1);
                indices.push_back(j + 1);

                break;
            }

            else if (numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }

        return indices;
    }
};