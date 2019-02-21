cmake_minimum_required(VERSION 3.12)
project("GscBoostSafeFloat")

if (TESTING)
  enable_testing()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(${PROJECT_NAME}_HEADERS} "tupleToVector.h")

if (TESTING)
  add_subdirectory("test")
endif()
