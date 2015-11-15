#include <iostream>
#include <cassert>



void swap( int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * reverse an array from index 'start' to index 'end'
 * @param arr   [The array]
 * @param start [The start index]
 * @param end   [The end index]
 */
void reverse( int * arr, int start, int end )
{
    while( start < end ) {
        swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}


/**
 * [leftRotate - rotate an array of length n with r rotations in left direction
 * @param arr - the array
 * @param n   - size of array
 * @param r   - n number of rotations
 */
void leftRotate( int* arr, int n, int r )
{
    r = r % n;
    reverse( arr, 0, r-1);
    reverse( arr, r, n-1);
    reverse( arr, 0, n-1);
}


/**
 * [rightRotate - rotate an array of length n with r rotations in left direction
 * @param arr - the array
 * @param n   - size of array
 * @param r   - n number of rotations
 */
void rightRotate( int* arr, int n, int r )
{
    r = r % n;
    reverse( arr, 0, n-1);
    reverse( arr, 0, r-1);
    reverse( arr, r, n-1);
}


int main()
{
    int n, r, d;
    std::cout << "Enter size of array :";
    std::cin >> n;
    std::cout << "Enter the contents of array:";
    int * arr = new int[n];
    for ( int i = 0; i < n; ++i ) {
        std::cin >> arr[i];
    }
    std::cout << "Enter number of rotations you need:";
    std::cin >> r;
    std::cout << "Direction (left = 0, right = 1):";
    std::cin >> d;
    assert((d == 0) || (d == 1));
    if ( d == 0 ) {
        leftRotate(arr, n, r);
    } else {
        rightRotate(arr, n, r);
    }
    std::cout << "The array after rotation:\n";
    for ( int i = 0; i < n; ++i ) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
