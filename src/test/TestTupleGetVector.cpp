#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleGetVector
#include <boost/test/unit_test.hpp>

#include <tupleGetVector.h>
#include <tupleToVector.h>

#include <test/testHelpers.h>

BOOST_AUTO_TEST_CASE( tupleOfTwoElementVectors )
{
  auto testTuple { toTupleOfVectors( 2, std::make_tuple( "one", 2 ) ) };
  BOOST_CHECK( "{{one, one}, {2, 2}}" == testTuple );
  auto& element { getVector<1>( testTuple ) };
  element[1] = 4;
  BOOST_CHECK( "{{one, one}, {2, 4}}" == testTuple );
}

BOOST_AUTO_TEST_CASE( tupleOfOneElementVectors )
{
  auto testTuple { toTupleOfVectors( 2, std::make_tuple( 1 ) ) };
  BOOST_CHECK( "{{1, 1}}" == testTuple );
  auto& element { getVector<0>( testTuple ) };
  element[1] = 4;
  BOOST_CHECK( "{{1, 4}}" == testTuple );
}

//BOOST_AUTO_TEST_CASE( tupleCheckTest )
//{
//  auto testTuple { std::make_tuple( std::vector<int>({1}), std::vector<int>({2}), 3 ) };
//  auto& element { getVector<0>( testTuple ) };
//}

//BOOST_AUTO_TEST_CASE( emptyTupleTest )
//{
//  auto testTuple { std::make_tuple() };
//  auto& element { getVector<0>( testTuple ) };
//}
