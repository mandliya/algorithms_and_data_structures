/*
 * Given a vector containing numbers, move all the 0s in the vector to the end.
 * example:
 * vec = [1, 0, 4, 5, 3, 0, 7, 8, 0, 10]
 * output = [1, 4, 5, 3, 7, 8, 10, 0, 0, 0]
 *
 * Idea is to move non-zero elements sequentially to next available position starting from 0.
 * After all elements in the array are processed, we fill all remaining indexes by 0.
 */

#include <iostream>
#include <vector>

void moveZeros(std::vector<int>& vec)
{
    unsigned int j = 0;
    unsigned int size = vec.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        if (vec[i] != 0)
            vec[j++] = vec[i];
    }

    while(j < size)
    {
        vec[j++] = 0;
    }
}

void printVector(const std::vector<int>& vec)
{
    std::cout << "Vector contents: ";
    for (auto x:vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vec {1, 0, 4, 5, 3, 0, 7, 8, 0, 10};
    printVector(vec);
    std::cout << "Moving zeros to the back..\n";
    moveZeros(vec);
    printVector(vec);
    return 0;
}