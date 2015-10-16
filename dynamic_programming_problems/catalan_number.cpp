/**
 *  Dynamic Programming problem
 *  Catalan number - How many binary search trees are possible with n keys.
 *  n = 1 , num of BST - 1
 *  n = 2 , num of BST - 2
 *
 *              2                 1
 *            /       and           \
 *          1                       2
 *
 *  n = 3, num of BST - 5
 *
 *            3          1               2             2                 3
 *          /             \             / \             \               /
 *        2       and     2     and   1   3   and       3     and     1
 *        /                \                            /               \
 *      1                  3                          1                2
 *
 * So, If we choose, ith element as root, there will be i-1 elements on the
 * left subtree and n-i on the right. The two side subtrees would be independent
 * of each other. Therefore we can say.
 * C(i) = C(i-1) * C(n-i)
 * Since there will be many subproblems, which will overlap, we can use dynamic
 * programming.
 */

#include <iostream>
#include <vector>


// calculating catalan number using DP, Time complexity O(n^2)
int catalan_number( int n ) {
  std::vector<int> table(n+1);
  table[0] = table[1] = 1;
  for ( int i = 2; i <= n; ++i ) {
    table[i] = 0;
    for ( int j = 0; j < i; ++j ) {
      table[i] += ( table[j] * table[i - j - 1] );
    }
  }
  return table[n];
}

int main()
{
  int n;
  std::cout << "Enter a number : ";
  std::cin >> n;
  std::cout << "Number of possible Binary Search Trees for " << n << " is "
            << catalan_number(n) << std::endl;
  return 0;
}
