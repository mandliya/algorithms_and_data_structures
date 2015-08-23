#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <cassert>

namespace algo {
    template <typename T>
        static void selectionSort( T list[ ], int start, int end )
        {
            assert( start <= end );
            int i, j, minIndex;
            
            for ( i = start; i <= end - 1; ++i ) {
                //let us assume element at start index is smallest
                minIndex = i;
                for ( j = start + 1; j <= end; ++j ) {
                    if ( list[j]  <  list[minIndex] ) {
                        minIndex = j;
                    }
                }
                //swap the min element with the element at current position
                if ( minIndex != i ) {
                    swap( list[i], list[minIndex] );
                }
            }
        }
}; //end of namespace algo
#endif
