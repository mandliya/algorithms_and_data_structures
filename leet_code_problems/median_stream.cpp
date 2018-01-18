/*
 * Source : Leetcode, 295. Find Median from Data Stream
 * Category : hard
 * 
 * Find median from a data stream. Design a data structure that supports addNum to add a number to the stream,
 * and findMedian to return the median of the current numbers seen so far.  Also, if the count of numbers is
 * even, return average of two middle elements, return median otherwise.
 * 
 * In naive approach, we could maintain an internal vector and sort the array everytime median is requested,
 * and return the middle element(when odd count) or mean of two middle elements (when mean count)
 * 
 * However, this doesn't scale well as the size of the vector grows, and if 'findMedian' is accessed too
 * frequently. We would want a potentially better solution which could reduce the cost of finding median,
 * even though we might make add a little slow.
 * 
 * We could use something which maintains a ordered stream of numbers, and median could be retrieved in O(1)
 * time, and add could be done in O(logn) time.
 * 
 * This could be achieved using a Self-Balanced Binary search tree, or using two heaps.
 * We will currently solve with a heap approach.
 * 
 * Why two heaps?
 * We want two middle numbers (in even count case), so if we maintain two heaps, one min-heap and other
 * max-heap, the max-heap will maintain the lower ordered half of the numbers while the min-heap would
 * maintained the upper half of the numbers.
 * Consider even number of numbers in stream so far, in that case, the top of the lower heap (max heap)
 * will contain the left middle number of the stream and top of upper heap (min heap) will contain the 
 * right middle number of the stream. Thus we could retrive the two middle numbers in O(1) time.
 * 
 * [1, 2, 3, 4, 5]  <-- values in lower heap. (MAX heap)
 * [6, 7, 8, 9, 10] <-- Values in upper heap. (MIN heap)
 * 
 * lower.top() = 5
 * upper.top() = 6
 * So we will want (6+5)/2 = 5.5 as answer.
 * 
 * Now, the algorithm:
 * In order to maintain the two middle numbers of the stream on the top of the two heaps,
 * we will have to balance them with each addition of new number.
 * 
 * In case of odd numbers, the lower heap will contain 1 number extra then the upper heap.
 * In case of even numbers, both the heaps will have equal numbers of elements.
 * 
 * As we add a new number, we will add it to lower, then we will balance the heaps by transferring
 * the top to upper heap, and then we will maintain the size property maintained above.
 */

#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <algorithm>

class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num)
    {
        // first add it to lower.
        lower.push(num);

        // balance the heaps to set the right values at the top.
        upper.push(lower.top());
        lower.pop();

        // Maintain the size property.
        if (lower.size() < upper.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian()
    {
        return (lower.size() > upper.size()) ? static_cast<double>(lower.top()) :
            (static_cast<double>(lower.top() + upper.top()) / 2);
    }

    // utility function to print current sorted stream.
    void printSortedStream()
    {
        std::priority_queue<int> lc{lower};
        std::priority_queue<int, std::vector<int>, std::greater<int>> uc{upper};
        std::vector<int> temp;
        // lower half first;
        while(!lc.empty()){
            temp.push_back(lc.top());
            lc.pop();
        }

        std::reverse(temp.begin(), temp.end());

        for (auto n: temp) {
            std::cout << n << " ";
        }

        while (!uc.empty()) {
            std::cout << uc.top() << " ";
            uc.pop();
        }

        std::cout << std::endl;
    }
private:
    // max heap maintaining the lower half of ordered stream.
    std::priority_queue<int> lower; 
    // min heap maintaining the upper half of ordered stream.
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;
};


int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,20);
    MedianFinder medianFinder;

    for (int i=0; i<5; ++i)
    {
        medianFinder.addNum(distribution(generator));
    }

    // current state of stream
    medianFinder.printSortedStream();
    std::cout << "Median of current stream: " << medianFinder.findMedian()
        << std::endl;

    // Add 5 more.
    //
    for (int i=0; i<5; ++i)
    {
        medianFinder.addNum(distribution(generator));
    }
    
     // current state of stream
    medianFinder.printSortedStream();
    std::cout << "Median of current stream: " << medianFinder.findMedian()
        << std::endl;

    return 0;
}