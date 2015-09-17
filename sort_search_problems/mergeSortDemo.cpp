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

//Simple merge sort demo for 10 random doubles and int
#include <generic.h>
#include <mergeSort.h>

int main()
{
    const int MAX_ELEMENTS = 10;
    int arr[MAX_ELEMENTS];
    double arrD[MAX_ELEMENTS];

    //Filling up the array with random numbers;
    for (int i = 0; i < MAX_ELEMENTS; ++i)
    {   
        arr[i] = algo::random_range(1, 100);
        arrD[i] = algo::random_range(1.0, 99.99);
    }

    std::cout << "Before Sorting:\n";
    algo::printList(arr, MAX_ELEMENTS);
    algo::mergeSort(arr, 0, MAX_ELEMENTS - 1);
    std::cout << "After Sorting:\n";
    algo::printList(arr, MAX_ELEMENTS);


    std::cout << "\n\nBefore Sorting:\n";
    algo::printList(arrD, MAX_ELEMENTS);
    algo::mergeSort(arrD, 0, MAX_ELEMENTS - 1);
    std::cout << "After Sorting:\n";
    algo::printList(arrD, MAX_ELEMENTS);
    return 0;
}

