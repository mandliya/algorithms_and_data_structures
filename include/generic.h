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

#ifndef GENERIC_H
#define GENERIC_H

#include <iostream>
#include <random>
#include <sstream>
#include <string>


template<typename T>
T MAX(T a, T b)
{
    return ((a > b) ? a : b);
}

template<typename T>
T MIN(T a, T b)
{
    return ((a < b) ? a : b);
}

namespace algo {
    // swap two elements
    template <typename T>
        static inline void swap(T &a, T &b)
        {
            T _temp(std::move(a));
            a = std::move(b);
            b = std::move(_temp);
        }

    //Print the list of T
    template <typename T>
        static inline void printList(T *list, int count)
        {
            for (int i = 0; i < count; ++i) {
                std::cout << list[i] << "  "; 
            }
            std::cout<< std::endl;
        }

    //generate a random int between min and max
    static inline int random_range(const int min, const int max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(mt);
    }

    //generate a random double between min and max
    static inline double random_range(const double min, const double max) {
        // std::random_device rd;
        // std::mt19937 mt(rd());
        std::uniform_real_distribution<double> distribution(min, max);
		std::default_random_engine re;
        return distribution(re);
    }

    //convert an int to string
    std::string intToString( int num ) {
        std::stringstream ss;
        ss << num;
        return ss.str();
    }

} //end of namespace algo


#endif //end of generic.h
