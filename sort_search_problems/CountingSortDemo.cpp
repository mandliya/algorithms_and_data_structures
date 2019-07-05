#include <cstdlib>
#include <CountingSort.h>
#include <generic.h>

int main() {
    int data[100];
    for(int i = 0; i<= 100;i++){
        data[i] = algo::random_range(1, 100);
    }
    algo::countingSort(data,0,100);
    algo::printList(data,100);
    return 0;
}