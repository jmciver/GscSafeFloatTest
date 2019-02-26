#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleToVector
#include <boost/test/unit_test.hpp>

#include <tupleToVector.h>
#include <tupleUtilities.h>

#include <sstream>
#include <string>
#include <vector>

BOOST_AUTO_TEST_CASE( testZeroElement )
{
  const std::string expectedValue { "{}" };
  BOOST_CHECK( expectedValue == toTupleOfVectors( 1, std::tuple<>() ) );
  BOOST_CHECK( expectedValue == toTupleOfVectors( 2, std::tuple<>() ) );
  BOOST_CHECK( expectedValue == toTupleOfVectors( 3, std::tuple<>() ) );
}

BOOST_AUTO_TEST_CASE( testOneElement )
{
  BOOST_CHECK( "{{1}}" == toTupleOfVectors( 1, std::make_tuple( 1 ) ) );
  BOOST_CHECK( "{{2, 2}}" == toTupleOfVectors( 2, std::make_tuple( 2 ) ) );
  BOOST_CHECK( "{{3, 3, 3}}" == toTupleOfVectors( 3, std::make_tuple( 3 ) ) );
  BOOST_CHECK( "{{a}}" == toTupleOfVectors( 1, std::make_tuple( "a" ) ) );
  BOOST_CHECK( "{{b, b}}" == toTupleOfVectors( 2, std::make_tuple( "b" ) ) );
  BOOST_CHECK( "{{c, c, c}}" == toTupleOfVectors( 3, std::make_tuple( "c" ) ) );
}

BOOST_AUTO_TEST_CASE( testTwoElements )
{
  BOOST_CHECK( "{{1}, {2}}" == toTupleOfVectors( 1, std::make_tuple( 1, 2 ) ) );
  BOOST_CHECK( "{{1, 1}, {2, 2}}" == toTupleOfVectors( 2, std::make_tuple( 1, 2 ) ) );
  BOOST_CHECK( "{{top, top}, {10, 10}, {3.14, 3.14}}" == toTupleOfVectors(
    2,
    std::make_tuple( "top", 10, 3.14 ) ) );
  BOOST_CHECK( "{{1, 1}, {1.1, 1.1}, {a, a}}" == toTupleOfVectors(
    2,
    std::make_tuple( 1, 1.1, 'a' ) ) );
}

BOOST_AUTO_TEST_CASE( testTupleOfVectors )
{
  BOOST_CHECK(
    "{{{1, 2, 3}, {1, 2, 3}}, {{a, b, c}, {a, b, c}}}" ==
    toTupleOfVectors(
      2,
      std::make_tuple(
        std::vector<int>( { 1, 2, 3 } ),
        std::vector<char>( { 'a', 'b', 'c' } ) ) ) );
}
