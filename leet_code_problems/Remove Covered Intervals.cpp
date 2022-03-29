// https : // leetcode.com/problems/remove-covered-intervals/

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int x1 = intervals[0][0];
        int x2 = intervals[0][1];

        int cnt = 1;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] > x1 and intervals[i][1] > x2)
            {
                cnt++;
            }

            if (intervals[i][1] > x2)
            {
                x1 = intervals[i][0];
                x2 = intervals[i][1];
            }
        }

        return cnt;
    }
};