// https : // practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st;
        for (int i = 0; i < N; i++)
            st.insert(arr[i]);

        int largest = 1;

        for (auto s : st)
        {
            int prev = s - 1;
            if (st.find(prev) == st.end())
            {
                int next = s + 1, cnt = 1;
                while (st.find(next) != st.end())
                    next++, cnt++;
                largest = max(largest, cnt);
            }
        }

        return largest;
    }
};