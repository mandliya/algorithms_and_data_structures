// https : // leetcode.com/problems/longest-mountain-in-array/

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int largest = 0;
        int n = arr.size();

        for (int i = 1; i <= n - 2;)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                int j = i;
                int count = 1;

                while (j >= 1 && arr[j - 1] < arr[j])
                {
                    count++;
                    j--;
                }

                while (i <= n - 2 && arr[i + 1] < arr[i])
                {
                    count++;
                    i++;
                }

                largest = max(largest, count);
            }
            else
            {
                i++;
            }
        }

        return largest;
    }
};