/*
1
1 2
3 5 8
13 21 34 55
89 144 233 377 610
*/


#include <iostream>
using namespace std;

int main() {
	int n, i, sum = 0;
	cin>>n;
	int cuml = n;

	//getting cumulative sum
	while(cuml>0){
	    sum += cuml;
	    cuml--;
	}

	//fibonaaci array generation
	int arr[200];
	arr[0] = 0;
	arr[1] = 1;
	for(i = 2; i <= sum; i++){
	    arr[i] = arr[i-1] + arr[i-2];
	}

	int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;j <= i;j++)
            cout << arr[num++] << " ";

        cout << endl;
    }

	return 0;
}
