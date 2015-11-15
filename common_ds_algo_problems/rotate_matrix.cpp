/**
 *  Given a 2D matrix, a, of dimension MxN and a positive integer R.
 *  You have to rotate the matrix R times and print the resultant matrix.
 *  Rotation should be in anti-clockwise direction.
 *
 *  Input : First line contains M (number of rows of matrix), N (number of columns in matrix)
 *  				and R (Number of rotations to be performed).Then M x N matrix is expected.
 *  Ouput : Matrix after R rotations.
 *
 *  Example :
 *  Input :
 *  				5 4 7
 *  				1 2 3 4
 *  				7 8 9 10
 *  				13 14 15 16
 *  				19 20 21 22
 *  				25 26 27 28
 *  Output :
 *  				28 27 26 25
 *  				22 9 15 19
 *  				16 8 21 13
 *  				10 14 20 7
 *  				4 3 2 1
 *
 *  Approach :
 *  Accumulate each bordering rectangle in a vector, shift it R rotations and copy it back to matrix.
 *  Keep doing for all levels till we have reached the center of matrix.
 */



#include <vector>
#include <iostream>
using namespace std;

void rotateLeftSingle(vector<int>& vec)
{
    int first = vec[0];
    for ( unsigned int i = 0; i < vec.size()-1; ++i) {
        vec[i] = vec[i+1];
    }
    vec[vec.size() - 1] = first;
}

void rotate(vector<int> & vec, long r) {
    r = r % vec.size();
    for ( int i = 0; i < r; ++i) {
        rotateLeftSingle(vec);
    }
}

int main() {
    long M, N, R;
    cin >> M >> N >> R;
    int ** matrix = new int*[M];
    for ( int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    for ( int i = 0; i < M; ++i) {
        for ( int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    int a = 0, b = N-1, c = M-1, d = 0;
    int al,bl,cl,dl;
    while( a < c && d < b ) {
        vector<int> currLevel;
        al = a;
        bl = b;
        cl = c;
        dl = d;
        for ( int j = d; j <= b; ++j ) {
            currLevel.push_back(matrix[a][j]);
        }
        ++a;
        for ( int i = a; i <= c; ++i) {
            currLevel.push_back(matrix[i][b]);
        }
        --b;
        for ( int j = b; j >= d; --j) {
            currLevel.push_back(matrix[c][j]);
        }
        --c;
        for ( int i = c; i >= a; --i ) {
            currLevel.push_back(matrix[i][d]);
        }
        ++d;
        rotate(currLevel, R);
        int k = 0;

        for ( int j = dl; j <= bl; ++j ) {
            matrix[al][j] = currLevel[k];
            ++k;
        }
        ++al;
        for ( int i = al; i <= cl; ++i) {
            matrix[i][bl] = currLevel[k];
            ++k;
        }
        --bl;
        for ( int j = bl; j >= dl; --j) {
            matrix[cl][j] = currLevel[k];
            ++k;
        }
        --cl;
        for ( int i = cl; i >= al; --i) {
            matrix[i][dl] = currLevel[k];
            ++k;
        }
        ++dl;
    }

    for ( int i = 0; i < M; ++i) {
        for ( int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
