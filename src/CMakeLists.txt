cmake_minimum_required(VERSION 3.12)
project("GscBoostSafeFloat")

set(CMAKE_CXX_STANDARD 17)

if (WIN32 AND MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /WX")
elseif("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")
else()
  message(WARNING "platform \"${CMAKE_SYSTEM_NAME}\" is untested")
endif()

if (TESTING)
  enable_testing(CMAKE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(${PROJECT_NAME}_HEADERS
  "positiveIntegerPowerLiteral.h"
  "tupleGetVector.h"
  "tupleToVector.h"
  "tupleUtilities.h" )

# The following custom target is used to provide inclusion of headers into an
# IDE project and thus produces no tangible compilation objects.
add_custom_target(${PROJECT_NAME} SOURCES ${${PROJECT_NAME}_HEADERS})

if (TESTING)
  add_subdirectory("test")
endif()
