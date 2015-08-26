/*** 
 *     _  __                ___      _                                   
 *     | |/ /___ ___ _ __   / __|__ _| |_ __                              
 *     | ' </ -_) -_) '_ \ | (__/ _` | | '  \
 *     |_|\_\___\___| .__/  \___\__,_|_|_|_|_|                            
 *                  |_|                                                   
 *                   _                                                    
 *      __ _ _ _  __| |                                                   
 *     / _` | ' \/ _` |                                                   
 *     \__,_|_||_\__,_|                                                   
 *                                                                        
 *      _                          _   _              _ _   _             
 *     | |   ___ __ _ _ _ _ _     /_\ | |__ _ ___ _ _(_) |_| |_  _ __  ___
 *     | |__/ -_) _` | '_| ' \   / _ \| / _` / _ \ '_| |  _| ' \| '  \(_-<
 *     |____\___\__,_|_| |_||_| /_/ \_\_\__, \___/_| |_|\__|_||_|_|_|_/__/
 *                                      |___/                             
 *     Yeah! Ravi let's do it! 
 */


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
} //end of namespace algo
#endif
