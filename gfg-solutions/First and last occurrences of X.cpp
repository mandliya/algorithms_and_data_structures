// https : // practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1/#

class Solution
{
public:
    int firstPosition(vector<int> arr, int x)
    {
        int pos = -1;
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x)
            {
                pos = mid;
                e = mid - 1;
            }
            else if (arr[mid] > x)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return pos;
    }

    int lastPosition(vector<int> arr, int x)
    {
        int pos = -1;
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x)
            {
                pos = mid;
                s = mid + 1;
            }
            else if (arr[mid] > x)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return pos;
    }

    vector<int> firstAndLast(vector<int> &arr, int n, int x)
    {
        vector<int> pos(2);

        pos[0] = firstPosition(arr, x);
        pos[1] = lastPosition(arr, x);

        if (pos[0] == -1)
        {
            return {-1};
        }

        return pos;
    }
};