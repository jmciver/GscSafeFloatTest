#ifndef gsc_boost_safeFloat_tupleUtilities_h
#define gsc_boost_safeFloat_tupleUtilities_h

#include <ostream>
#include <tuple>

template<class Tuple, std::size_t N>
struct TuplePrinter
{
  static void print( std::ostream& stream, const Tuple& tuple )
  {
    TuplePrinter<Tuple, N-1>::print( stream, tuple );
    stream << ", " << std::get<N-1>( tuple );
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1>
{
  static void print( std::ostream& stream, const Tuple& tuple )
  {
    stream << std::get<0>( tuple );
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 0>
{
  static void print( std::ostream&, const Tuple& )
  {
    // Empty.
  }
};

template<class... Args>
std::ostream& operator<< ( std::ostream& stream,  const std::tuple<Args...>& tuple )
{
  stream << "(";
  TuplePrinter<decltype( tuple ), sizeof...(Args)>::print( stream, tuple );
  stream << ")";
  return stream;
}

std::ostream& operator<< ( std::ostream& stream,  const std::tuple<>& tuple )
{
  stream << "(";
  TuplePrinter<decltype( tuple ), 0>::print( stream, tuple );
  stream << ")";
  return stream;
}

#endif // gsc_boost_safeFloat_tupleUtilities_h
