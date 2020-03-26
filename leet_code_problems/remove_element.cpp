/*
 * Source LeetCode Problem 27 Remove element.
 * Given an array and a value, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * 
 * Approach:
 * 
 * The idea is to use two pointers, one iterates the entire nums(i), and the other one maintains the length of set of numbers
 * which we want in our output.(j). The idea is everytime we find a wanted element we move the j. This way j maintains all
 * the wanted element at top of the nums.
 */

#include <iostream>
#include <vector>


int remove_element(std::vector<int>& nums, int value)
{
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != value) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

void print_vector(std::vector<int>& nums, int count)
{
    for (int i = 0; i < count; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums = {2, 2, 3, 4, 4, 5, 6, 2, 4, 3, 2, 3};
    std::cout << "Vector: ";
    print_vector(nums, nums.size());
    int count = remove_element(nums, 2);
    std::cout << "Removing 2 from above vector: ";
    print_vector(nums, count);
    return 0;
}