#ifndef gscBoost_safeFloat_tupleUtilities_h
#define gscBoost_safeFloat_tupleUtilities_h

#include <boost/algorithm/string.hpp>

#include <ostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

template <class T>
std::string convertVectorToString( const std::vector< T >& vector )
{
  std::vector<std::string> vectorAsStrings;
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
  stream << "{" << convertVectorToString( vector ) << "}";
  return stream;
}

template <class Tuple, std::size_t N>
struct TuplePrinter
{
  static void print( std::ostream& stream, const Tuple& tuple )
  {
    TuplePrinter<Tuple, N-1>::print( stream, tuple );
    stream << ", " << std::get<N-1>( tuple );
  }
};

template <class Tuple>
struct TuplePrinter<Tuple, 1>
{
  static void print( std::ostream& stream, const Tuple& tuple )
  {
    stream << std::get<0>( tuple );
  }
};

template <class Tuple>
struct TuplePrinter<Tuple, 0>
{
  static void print( std::ostream&, const Tuple& )
  {
    // Empty.
  }
};

template <class... Elements>
std::ostream& operator<< ( std::ostream& stream,  const std::tuple<Elements...>& tuple )
{
  stream << "{";
  TuplePrinter<decltype( tuple ), sizeof...( Elements )>::print( stream, tuple );
  stream << "}";
  return stream;
}

#endif // gscBoost_safeFloat_tupleUtilities_h
