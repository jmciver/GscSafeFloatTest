find_package( Boost REQUIRED unit_test_framework )

function(simpleTest name)
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(${name} testHelpers.h "${name}.cpp")
  target_link_libraries(${name} ${Boost_LIBRARIES})

  add_test(NAME "${name}" COMMAND "${name}")
endfunction()

simpleTest("TestPositiveIntegerPowerLiteral")
simpleTest("TestTupleToVector")
simpleTest("TestTupleUtilities")
simpleTest("TestTupleGetVector")
