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

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

namespace algo {
    template <typename T>
        static void __merge ( T *list, int left, int mid, int right )
        {
            // a temporary array to store merged result
            T merged[right - left + 1];
            int currIter = 0, leftIter = left, rightIter = mid + 1;
            while ( leftIter <= mid && rightIter <= right ) {
                if ( list[leftIter] < list[rightIter] )
                {
                    merged[currIter++] = list[leftIter++];
                } else {
                    merged[currIter++] = list[rightIter++];
                }
            }

            while ( leftIter <= mid ) {
                    merged[currIter++] = list[leftIter++];
            }

            while ( rightIter <= right ) {
                    merged[currIter++] = list[rightIter++];
            }
            
            //copying the entire merged array back
            for ( int i = 0; i < currIter; ++i ) {
                list[ i + left] = merged[i];
            }

        }

    template <typename T>
        static void mergeSort( T *list, int start, int end )
        {
            int mid = ( start + end )/2 ;
            if ( start < end ) {
                mergeSort( list, start, mid );
                mergeSort( list, mid + 1, end );
                __merge( list, start, mid, end);
            }
        }
} //end of namespace algo

#endif
