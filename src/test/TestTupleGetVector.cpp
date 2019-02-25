#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleUtilities
#include <boost/test/unit_test.hpp>

#include <tupleGetVector.h>

BOOST_AUTO_TEST_CASE( testEmpty )
{
  BOOST_CHECK( true );
}
