#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleUtilities

#include <tupleUtilities.h>

#include <sstream>
#include <tuple>

#include <boost/test/unit_test.hpp>

template<class... Args>
bool operator== ( const std::string& lhs, const std::tuple<Args...>& rhs )
{
  std::ostringstream stream;
  stream << rhs;
  return lhs.compare( stream.str() ) == 0 ? true : false;
}

bool operator== ( const std::string& lhs, const std::tuple<>& rhs )
{
  std::ostringstream stream;
  stream << rhs;
  return lhs.compare(stream.str()) == 0 ? true : false;
}

BOOST_AUTO_TEST_CASE(testPrintEmpty)
{
  const std::tuple<> empty;
  BOOST_CHECK( "()" == empty );
}

BOOST_AUTO_TEST_CASE(testPrintOne)
{
  const std::tuple<int> testTuple { std::make_tuple( 123 ) };
  BOOST_CHECK( "(123)" == testTuple );
}

BOOST_AUTO_TEST_CASE(testPrintTwo)
{
  auto testTuple = std::make_tuple( 123, "polymer" );
  BOOST_CHECK( "(123, polymer)" == testTuple );
}
