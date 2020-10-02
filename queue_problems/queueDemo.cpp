#include <iostream>
#include "../include/queue.h"
#include "../include/generic.h"
using namespace std;

int main()
{
    const int QUEUE_SIZE = 10;
    algo::Queue<int> Q(QUEUE_SIZE);

    cout << "Pushing following values to queue:\n";
    for ( int i = 0; i < QUEUE_SIZE; ++i )
    {
        int rand_value = algo::random_range( 5, 50 );
		cout << rand_value << " ";
        Q.push(rand_value);
    }
    cout << endl;
    cout << "Size of Queue is :" << Q.count() << endl;
    cout << "\nPopping queue values :\n";
    while ( !Q.empty() ) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << std::endl;
    return 0;
}
