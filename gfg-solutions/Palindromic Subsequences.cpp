// https : // practice.geeksforgeeks.org/problems/palindromic-subsequences1335/1#

int MinRemove(int n, string s)
{

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return 2;
        }

        i++;
        j--;
    }

    return 1;
}