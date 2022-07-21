// https : // practice.geeksforgeeks.org/problems/set-bits0143/1#

class Solution
{
public:
    int setBits(int N)
    {
        int cnt = 0;
        while (N != 0)
        {
            N = N & (N - 1);
            cnt++;
        }
        return cnt;
    }
};