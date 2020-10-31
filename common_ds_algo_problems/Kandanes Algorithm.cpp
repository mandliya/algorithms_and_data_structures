#include <iostream>
#include <climits>
using namespace std;
 
#define MAX(X, Y) (X > Y) ? X : Y
#define POS(X) (X > 0) ? X : 0
 
int maxSum = INT_MIN;
int num;
int kadane(int* row, int len)
{
    int x, sum, maxSum = INT_MIN;
    for (sum = POS(row[0]), x = 0; x < num; ++x, sum = POS(sum + row[x]))
        maxSum = MAX(sum, maxSum);
    return maxSum;
}
 
int main()
{
    cout << "Enter the array length: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Max Sum is: "<<kadane(arr, n) << endl;
    return 0;
}
