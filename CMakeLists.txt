cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)

option(BUILD_TOOLS "Build EKA2L1's tools (Broken)" OFF)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set (ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src/external)
add_subdirectory(src/tests)
add_subdirectory(src/emu)

if (BUILD_TOOLS)
	add_subdirectory(tools)
endif()
