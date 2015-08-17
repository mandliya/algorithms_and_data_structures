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


#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <generic.h>

namespace algo {

    //Partition routine for quicksort
    template <typename T>
        static int __partition(T list[], int start, int end)
        {
            int pivotIndex = random_range(start, end);
            T pivot = list[pivotIndex];

            //Swapping pivot element with element at start
            swap(list[start], list[pivotIndex]);
            
            int i = start + 1;
            int j = end;
            while (i <= j) {
                while ((i <= end) && (list[i] <= pivot)) {
                    ++i;
                }
                while ((j >= start) && (list[j] > pivot)) {
                    --j;
                }
                if (i < j) {
                    swap(list[i], list[j]);
                }
            }
            swap(list[start], list[j]);
            return j;
        }

    //quickSort Routine
    template <typename T>
        static void quickSort(T list[], int start, int end)
        {
            if (start < end) {
                int pivotIndex = __partition<T>(list, start, end);
                quickSort(list, start, pivotIndex - 1);
                quickSort(list, pivotIndex + 1, end);
            }
        }


}//end of namespace algo
#endif //end of quickSort.h

