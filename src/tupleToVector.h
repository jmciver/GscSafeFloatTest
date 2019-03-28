// File: tupleToVector.h
// Description: Implementation of programming competency test 2 of 3.
#ifndef gscBoost_safeFloat_tupleToVector_h
#define gscBoost_safeFloat_tupleToVector_h

#include <tuple>
#include <vector>

namespace gscBoost {
namespace safeFloat {

namespace detail {

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

} // namespace detail

/// @brief Implementation of programming competency test 2 of 3.
template <class... Elements>
auto toTupleOfVectors(
  const std::size_t size,
  const std::tuple<Elements...>& tuple )
{
  return detail::TupleElementToVector<
    decltype( tuple ), sizeof... ( Elements )>::build( size, tuple );
}

} // namespace safeFloat
} // namespace gscBoost

#endif // gscBoost_safeFloat_tupleToVector_h
