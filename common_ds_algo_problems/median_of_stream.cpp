#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

void find_median(int x, double &median){
    if(max_heap.size() > min_heap.size()){
        if(x < median){
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(x);
            
            median = ((double) min_heap.top() + (double) max_heap.top()) / 2.0;
        }
        else{
            min_heap.push(x);
            median = ((double) min_heap.top() + (double) max_heap.top()) / 2.0;
        }
    }
    else if(max_heap.size() == min_heap.size()){
        if(x < median){
            max_heap.push(x);
            median = (double)max_heap.top();
        }
        else{
            min_heap.push(x);
            median = (double)min_heap.top();
        }
    }
    else{
        if(x < median){
            max_heap.push(x);
            median = ((double) min_heap.top() + (double) max_heap.top()) / 2.0;
        }
        else{
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(x);
            median = ((double) min_heap.top() + (double) max_heap.top()) / 2.0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    double median=0.0;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        find_median(arr[i], median);
        cout << setprecision(1) << fixed << median << endl;
    }
    return 0;
}
