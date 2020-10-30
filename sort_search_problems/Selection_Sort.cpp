#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void
swapi (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
  // cout << *a << " " << *b << endl;
}


vector < int >
selectionSort (vector < int >arr, int n)
{
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray  
  for (i = 0; i < n - 1; i++)
    {
      // Find the minimum element in unsorted array  
      min_idx = i;
      for (j = i + 1; j < n; j++)
	if (arr[j] < arr[min_idx])
	  min_idx = j;

      // Swap the found minimum element with the first element  
      swapi (&arr[min_idx], &arr[i]);
    }
  return arr;
}



int
main ()
{
//   cout << "Hello World\n";
  std::vector < int >vec;
  vec = {202, 4, -5, 66, -2, 0, 96, 5, 78, 12, 48, 88};

  vec = selectionSort (vec, vec.size());
    for (int x:vec)
    {
      cout << x << " ";
    }
  return 0;
}
