#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H


#include <vector>
#include <deque>

namespace algo {
    struct tuple {
        int count;
        int key;
    };

    static void countingSort(int list[], int start, int end) {
        std::deque<tuple> data;
        int max = list[start];
        for (int i = start + 1; i <= end; i++) {
            if (list[i] > max) {
                max = list[i];
            }
        }
        for (int i = 0; i <= max; i++) {
            int num = 0;
            for (int j = start; j <= end; j++) {
                if (list[j] == i) {
                    num++;
                }
            }
            if (num) {
                tuple t;
                t.key = i;
                t.count = num;
                data.push_back(t);
            }
        }
        int point = 0;
        for(tuple i : data){
            for(int j =0 ; j <= i.count; j++){
                list[point] = i.key;
                if(point < end-start) {
                    point++;
                }
            }
        }
    }
}


#endif
