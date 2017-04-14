#include <iostream>
#include <vector>

void printCommonElements(const std::vector<int>& vec1,
                         const std::vector<int>& vec2,
                         const std::vector<int>& vec3)
{
    std::vector<int>::const_iterator it1 = vec1.begin();
    std::vector<int>::const_iterator it2 = vec2.begin();
    std::vector<int>::const_iterator it3 = vec3.begin();

    while (it1 != vec1.end() && it2 != vec2.end() && it3 != vec3.end())
    {
        if (*it1 == *it2 && *it2 == *it3)
        {
            std::cout << *it1 << " ";
            it1++;
            it2++;
            it3++;
        }
        else if (*it1 < *it2)
        {
            ++it1;
        }
        else if (*it2 < *it3)
        {
            ++it2;
        }
        else
        {
            ++it3;
        }
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vec1 {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::vector<int> vec2 {3, 6, 9, 12, 15, 18, 21};
    std::vector<int> vec3 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    printCommonElements(vec1, vec2, vec3);
    return 0;
}