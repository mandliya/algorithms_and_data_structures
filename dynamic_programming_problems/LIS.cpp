#include <iostream>
using namespace std;

int lis(int* input, int n) {
	int* output = new int[n];
	output[0] = 1;
	for (int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] > input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (best < output[i]) {
			best = output[i];
		}
	}
	delete [] output;
	return best;
}

int main() {
	int n;
	cin >> n;
	int * input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int ans = lis(input, n);
	cout << ans << endl;
	delete [] input;
}

