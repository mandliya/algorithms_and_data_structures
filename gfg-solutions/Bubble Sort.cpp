// https : // practice.geeksforgeeks.org/problems/bubble-sort/1#

class Solution
{
public:
    void bubbleSort(int arr[], int n)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            int flag = 0;

            for (int j = 0; j <= n - 2; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                break;
            }
        }
    }
};
