/*
 * Find intersection of two arrays/vectors:
 * Given two vectors find the result of their interaction. 
 * The result should only contain unique characters and can be in any order.
 * 
 * [1 2 3 3 4 4 5 5]
 * [2 3 5 5 4 4 6]
 * Result: [2 3 5 4] or [2 3 4 5]
 */

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> find_intersection(const std::vector<int>& vec1,
    const std::vector<int>& vec2)
{
    std::vector<int> result;
    std::unordered_set<int> set(vec1.begin(), vec1.end());
    for (int num : vec2) {
        if (set.erase(num)) {
            result.push_back(num);
        }
    }
    return result;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (auto n: vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec1 {1, 2, 3, 3, 4, 4, 5, 5};
    std::vector<int> vec2 {2, 3, 5, 5, 4, 4, 6};
    std::cout << "Vec 1: ";
    print_vector(vec1);
    std::cout << "Vec 2: ";
    print_vector(vec2);
    std::vector<int> result = find_intersection(vec1, vec2);
    std::cout << "Result: ";
    print_vector(result);
    return 0;
}