#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleUtilities
#include <boost/test/unit_test.hpp>

#include <test/testHelpers.h>

#include <tuple>

using namespace gscBoost::safeFloat;

BOOST_AUTO_TEST_CASE( testPrintEmpty )
{
  const std::tuple<> empty;
  BOOST_CHECK( "{}" == empty );
}

BOOST_AUTO_TEST_CASE( testPrintOne )
{
  const std::tuple<int> testTuple { std::make_tuple( 123 ) };
  BOOST_CHECK( "{123}" == testTuple );
}

BOOST_AUTO_TEST_CASE( testPrintTwo )
{
  auto testTuple = std::make_tuple( 123, "polymer" );
  BOOST_CHECK( "{123, polymer}" == testTuple );
}
