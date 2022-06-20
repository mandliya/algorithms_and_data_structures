// https : // practice.geeksforgeeks.org/problems/find-transition-point-1587115620/0/#

int transitionPoint(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (0 != arr[i])
        {
            return i;
        }
    }

    return -1;
}