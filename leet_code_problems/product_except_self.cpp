/*
 * Given an array of n integers where n > 1, nums, return an array output
 * such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Example: [1, 2, 3, 4] ==> [24, 12, 8, 6]
 * 
 * Try to use constant space. (excluding result array)
 */

#include <iostream>
#include <vector>


/*
 * Idea is to maintain two product variables, one from beginning and 
 * one from the end.
 * Each result variable in result array
 * would be touched twice, one from the left to right
 * and other right to left, thus producing desired result.
 */
std::vector<int> product_except_self(const std::vector<int>& nums)
{
    int product_from_beginning = 1;
    int product_from_end = 1;
    unsigned int n = nums.size();
    std::vector<int> result(n, 1);
    for (unsigned int i = 0; i < n; ++i) {
        result[i] *= product_from_beginning;
        product_from_beginning *= nums[i];
        result[n-1-i] *= product_from_end;
        product_from_end *= nums[n-1-i];
    }
    return result;
}
void print_vector(const std::vector<int>& vec)
{
    for (auto n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4};
    std::cout << "Input Vector: ";
    print_vector(vec);
    std::vector<int> result = product_except_self(vec);
    std::cout << "Output Vector: ";
    print_vector(result);
}

