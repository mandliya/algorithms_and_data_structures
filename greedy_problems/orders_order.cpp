/*
 * John is taking orders. 
 * The ith order is placed by the ith customer at ti time and it takes di time to procees. 
 * What is the order in which the customers will get their orders?
 *
 * Input
 * On the first line you will get n, the number of orders.
 * Then n lines will follow. On the (i+1)th line, you will get ti and di separated by a single space.
 *
 * Output
 * Print the order ( as single space separated integers ) in which the burger customers get their orders. 
 * If two customers get the order at the same time,
 * then print the smallest numbered order first.(remember, the customers are numbered 1 to n).
 *
 * Approach :
 * By greedy approach, we can conclude the customer who ordered first and his order duration is smaller will get his order first.
 * So we will sort the orders based on time at which order was taken, + duration it will take to fulfill that order.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct order {
  int index;
  int time;
  int duration;
};

bool compareFunc(order & o1, order & o2) {
    if ( (o1.time + o1.duration) < (o2.time + o2.duration) ) {
        return true;
    } else if ( o1.time + o1.duration == o2.time + o2.duration ) {
        if (o1.index < o2.index) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N ;
    order * orders = new order[N];
    for (int i = 0; i < N; ++i) {
        orders[i].index = i+1;
        cin >> orders[i].time;
        cin >> orders[i].duration;
    }
    sort(orders, orders+N, compareFunc);
    for( int i = 0; i < N; ++i) {
        std::cout << orders[i].index << " ";
    }
    std::cout << std::endl;
    return 0;
}

