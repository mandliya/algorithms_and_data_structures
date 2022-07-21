// https: // leetcode.com/problems/magnetic-force-between-two-balls/

class Solution
{
public:
    bool can_place(vector<int> &position, int m, int mid)
    {
        int n = position.size();
        int ball = 1;
        int last_position = position[0];

        for (int i = 1; i < n; i++)
        {
            int curr_position = position[i];
            if ((curr_position - last_position) >= mid)
            {
                last_position = curr_position;
                ball++;
            }

            if (ball == m)
            {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int> &position, int m)
    {

        int n = position.size();
        sort(position.begin(), position.end());
        int s = 1;
        int e = position[n - 1] - position[0];

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (can_place(position, m, mid))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return e;
    }
};