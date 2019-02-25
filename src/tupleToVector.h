#ifndef gsc_boost_safeFloat_tupleToVector_h
#define gsc_boost_safeFloat_tupleToVector_h

#include <tuple>
#include <vector>

template <class Tuple, std::size_t N>
struct TupleElementToVector
{
  static auto build( const std::size_t size, const Tuple& tuple )
  {
    return std::tuple_cat(
      TupleElementToVector<Tuple, N-1>::build( size, tuple ),
      std::make_tuple( std::vector( size, std::get<N-1>( tuple ) ) ) );
  }
};

template <class Tuple>
struct TupleElementToVector<Tuple, 1>
{
  static auto build( const std::size_t size, const Tuple& tuple )
  {
    return std::make_tuple( std::vector( size, std::get<0>( tuple ) ) );
  }
};

template <class Tuple>
struct TupleElementToVector<Tuple, 0>
{
  static auto build( const std::size_t, const Tuple& )
  {
    return std::make_tuple();
  }
};

template <class... Args>
auto toTupleOfVectors( const std::size_t size, const std::tuple<Args...>& tuple )
{
  return TupleElementToVector<decltype( tuple ), sizeof...(Args)>::build( size, tuple );
}

#endif // gsc_boost_safeFloat_tupleToVector_h
