/*
 * Given a sorted array, remove duplicates in place and return the new length.
 * It doesn't matter what is in array beyond the unique elements size.
 * Expected O(1) space and O(n) time complexity.
 * Input : {1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7, 7}
 * Output: {1, 2, 3, 4, 5, 6, 7}
 */

#include <iostream>
#include <vector>


template <typename T>
void swap(T& a, T& b)
{
    T c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}

unsigned int remove_duplicates(std::vector<int>& nums)
{
    unsigned int i = 0;
    for (unsigned int j = 0; j < nums.size(); ++j) {
        if (nums[i] != nums[j]) {
            swap(nums[++i], nums[j]);
        }
    }
    return i+1;
}

void print_vector(const std::vector<int>& vec, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) {
        std::cout <<  vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7, 7};
    std::cout << "Original vector:";
    print_vector(vec, vec.size());
    unsigned int size = remove_duplicates(vec);
    std::cout << "Output vector:";
    print_vector(vec, size);
    return 0;
}