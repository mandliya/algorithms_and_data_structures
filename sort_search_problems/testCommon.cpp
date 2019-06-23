#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>

using namespace std;

vector<int> commonElements(const std::vector<int>& vec1, const std::vector<int>& vec2, const std::vector<int>& vec3)
{
    std::vector<int>::const_iterator it1 = vec1.begin();
    std::vector<int>::const_iterator it2 = vec2.begin();
    std::vector<int>::const_iterator it3 = vec3.begin();
	vector<int> vec4;

    while (it1 != vec1.end() && it2 != vec2.end() && it3 != vec3.end())
    {
        if (*it1 == *it2 && *it2 == *it3)
        {
            std::cout << *it1 << " ";
			vec4.push_back(*it1);
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
	return vec4;
}

TEST_CASE("Closest one common in small arrays"){
	vector<int> l_first {0, 15, 50, 100};
	vector<int> l_second {15, 30, 45}; 
	vector<int> l_third {1, 2, 3, 15};
	vector<int> mine = commonElements(l_first, l_second, l_third);
	REQUIRE( mine.size() == 1 );
	REQUIRE( mine.at(0) == 15 );
}

TEST_CASE("Closest common in larger arrays"){
	vector<int> l_first {0, 15, 50, 100, 150, 200, 250, 300, 350};
	vector<int> l_second {15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 200, 210, 225, 240}; 
	vector<int> l_third {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210};
	vector<int> mine = commonElements(l_first, l_second, l_third);
	REQUIRE( mine.size() == 2 );
	REQUIRE( mine.at(0) == 150 );
	REQUIRE( mine.at(1) == 200 );
}