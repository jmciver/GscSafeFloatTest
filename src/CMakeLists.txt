cmake_minimum_required(VERSION 3.12)
project("GscBoostSafeFloat")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

if (TESTING)
  enable_testing()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(${PROJECT_NAME}_HEADERS} "tupleToVector.h")

if (TESTING)
  add_subdirectory("test")
endif()
