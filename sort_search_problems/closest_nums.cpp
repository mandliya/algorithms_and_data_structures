/*
Given a list of unsorted integers, A={a1,a2,…,aN}, Find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.
Input: N= Number of elements, followed by N elements.
Output: Output the pairs of elements with the smallest difference. If there are multiple pairs, output all of them in ascending order, all on the same line (consecutively) with just a single space between each pair of numbers. If there's a number which lies in two pair, print it two times
Example:
    Input : 4
            5 4 3 2
    Output: 2 3 3 4 4 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int N;
    vector<int> vec;
    cin >> N;
    int x;
    for ( int i = 0; i < N; ++i) {
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int mindiff = INT_MAX;
    for( size_t i = 0; i < vec.size()-1; ++i){
        if (vec[i+1]-vec[i] < mindiff) {
            mindiff = vec[i+1]-vec[i];
        }
    }
    for( size_t i =0; i < vec.size()-1; ++i ) {
        if (vec[i+1]-vec[i] == mindiff) {
            std::cout << vec[i] << " " << vec[i+1] << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

