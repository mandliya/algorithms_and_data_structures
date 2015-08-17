cmake_minimum_required (VERSION 2.6)
project (anAlgoProbAday)

#dirctory headers
include_directories(include)

#Files
file(GLOB QUICKSORT "quickSortDemo/*.cpp")

#compile flags
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable(quickSort ${QUICKSORT})
