#include <iostream>

void spiral_print_matrix( int ** matrix, int m, int n)
{
  int a = 0, b = n-1, c = m-1, d = 0;
  while( a < c && d < b) {
    for(int i = d; i <= b; ++i ) {
      std::cout << matrix[a][i] << " ";
    }

    ++a;

    for( int j = a; j <= c; ++j ) {
      std::cout << matrix[j][b] << " ";
    }

    --b;

    for( int i = b; i >= d; --i ) {
      std::cout << matrix[c][i] << " ";
    }

    --c;

    for( int j = c; j >= a; --j) {
      std::cout << matrix[j][d] << " ";
    }
    ++d;
  }
  std::cout << std::endl;
}

int main()
{
  int m, n;
  std::cout << "Enter num of rows :" ;
  std::cin >> m;
  std::cout << "Enter num of columns : ";
  std::cin >> n;
  int ** matrix = new int*[m];
  for ( int i = 0; i < m; ++i ) {
      matrix[i] = new int[n];
  }
  std::cout << "Enter content of matrix of size "
            << m << " * " << n << " :";
  for( int i = 0; i < m; ++i ) {
    for( int j = 0; j < n; ++j ) {
      std::cin >> matrix[i][j];
    }
  }
  std::cout << "Printing content of above matrix in spiral order:\n";
  spiral_print_matrix(matrix, m, n);
  return 0;
}
