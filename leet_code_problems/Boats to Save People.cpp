// https : // leetcode.com/problems/boats-to-save-people/

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {

        sort(people.begin(), people.end());

        int cnt = 0;
        int n = people.size();
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            int sum = people[i] + people[j];

            if (sum <= limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                j--;
                cnt++;
            }
        }

        return cnt;
    }
};