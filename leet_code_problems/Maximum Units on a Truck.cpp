// https : // leetcode.com/problems/maximum-units-on-a-truck/

class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int max_units = 0;

        sort(boxTypes.begin(), boxTypes.end(), comparator);

        for (int i = 0; i < n; i++)
        {
            if (truckSize - boxTypes[i][0] >= 0)
            {
                max_units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                max_units += truckSize * boxTypes[i][1];
                break;
            }
        }

        return max_units;
    }
};