
#include <iostream>
#include "list.h"
using namespace algo;

void print( const List<int>& lst ) {
    for (List<int>::const_iterator it = lst.begin() ; it != lst.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main( )
{
    const int N = 20;
    List<int> lst;
    
    for( int i = N - 1; i > 0; --i )
    {
        lst.push_front( i );
    }
    print(lst);
 
    return 0;
}

