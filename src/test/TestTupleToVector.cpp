#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestTupleToVector
#include <boost/test/unit_test.hpp>

#include <tupleToVector.h>
#include <tupleUtilities.h>

#include <boost/algorithm/string.hpp>

#include <sstream>
#include <string>
#include <vector>

template <class T>
std::string convertVectorToString( const std::vector< T >& vector )
{
  std::vector< std::string > vectorAsStrings;
  std::transform(
    begin( vector ),
    end( vector ),
    std::back_inserter( vectorAsStrings ),
      []( const T& item ) {
        std::ostringstream stream;
        stream << item;
        return stream.str(); } );
  return boost::algorithm::join( vectorAsStrings, ", " );
}

template <class T>
std::ostream& operator<< ( std::ostream& stream, const std::vector< T >& vector )
{
  stream << "(" << convertVectorToString( vector ) << ")";
  return stream;
}

BOOST_AUTO_TEST_CASE( testZeroElement )
{
  const std::string expectedValue { "()" };
  BOOST_CHECK( expectedValue == toTupleOfVectors( 1, std::tuple<>() ) );
  BOOST_CHECK( expectedValue == toTupleOfVectors( 2, std::tuple<>() ) );
  BOOST_CHECK( expectedValue == toTupleOfVectors( 3, std::tuple<>() ) );
}

BOOST_AUTO_TEST_CASE( testOneElement )
{
  BOOST_CHECK( "((1))" == toTupleOfVectors( 1, std::make_tuple( 1 ) ) );
  BOOST_CHECK( "((2, 2))" == toTupleOfVectors( 2, std::make_tuple( 2 ) ) );
  BOOST_CHECK( "((3, 3, 3))" == toTupleOfVectors( 3, std::make_tuple( 3 ) ) );
}
