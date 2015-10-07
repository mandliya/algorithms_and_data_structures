#ifndef HEAP_SORT
#define HEAP_SORT

#include <generic.h>
#include <cassert>

namespace algo {

    template <typename T>
      static void __sift_down(T list[], int low, int high) {
        int root = low;
        while( (root * 2 + 1) <= high ) {
          int left_child = root * 2 + 1;
          int right_child = left_child + 1;
          int swpIdx = root;
          //if root is less than left child.
          if ( list[root] < list[left_child] ) {
            swpIdx = left_child;
          }
          // if right child exists and bigger
          if ( (right_child <= high) && list[swpIdx] < list[right_child] ) {
            swpIdx = right_child;
          }

          if ( swpIdx != root ) {
            algo::swap( list[swpIdx], list[root] );
          } else {
            break;
          }
          //keep going down
          swpIdx = root;
        }
      }

    template <typename T>
      static void __heapify(T list[], int low, int high) {
        int mid = (high - low - 1)/2;
        while( mid >=0 ) {
          __sift_down(list, mid, high);
          --mid;
        }
      }

    template <typename T>
      static void heap_sort(T list[], int size) {
        assert(list);
        assert(size > 0);

        //heapify the list
        __heapify(list, 0, size-1);

        int high = size - 1;
        while ( high > 0 ) {
          algo::swap(list[high], list[0]);
          --high;
          __heapify(list, 0, high);
        }
      }
}
#endif
