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



#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "generic.h"

namespace algo {
    template <typename T>
        static void bubbleSort(T list[], int start, int end)
        {
            bool swapped;
            do {
                swapped = false;
                for (int i = start + 1; i <= end; ++i) {
                    if (list[i-1] > list[i]) {
                        swapped = true;
                        swap(list[i-1], list[i]);
                    }
                }
            } while (swapped);
        }
} //end of namespace algo

#endif
