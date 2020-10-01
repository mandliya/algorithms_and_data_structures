// A recursive solution to the Josephus Problem.

#include <iostream> 
using namespace std; 

int josephus(int n, int k) 
{ 
	if (n == 1) 
		return 1; 
	else
		/* The position returned by josephus(n - 1, k) 
		is adjusted because the recursive call 
		josephus(n - 1, k) considers the 
		original position k % n + 1 as position 1 */
		return (josephus(n - 1, k) + k-1) % n + 1; 
} 

// Driver Program to test above function 
int main() 
{ 
	int n, k;
  cin>>n>>k;
	cout << "The chosen place is " << josephus(n, k); 
	return 0; 
}
