cmake_minimum_required (VERSION 2.6)
project (anAlgoProbAday)

#dirctory headers
include_directories("include")
include_directories(".")

#Files
file(GLOB SOURCES "./*/*.cpp")

#compile flags
set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g -pedantic")

foreach( sourcefile ${SOURCES} )
        get_filename_component( demo_name ${sourcefile} NAME_WE )
		if (${demo_name} STREQUAL "pstring")
			add_library(pstring ${sourcefile})
            continue()
		endif()
		if (${demo_name} STREQUAL "pUnitTest")
			add_library(pUnitTest ${sourcefile})
            continue()
		endif()
        add_executable( ${demo_name} ${sourcefile} )
		if (${demo_name} STREQUAL "pstring_test")
			target_link_libraries (${demo_name} pstring pUnitTest)
		endif()
            continue()
		endif()
endforeach( sourcefile ${SOURCES} )
