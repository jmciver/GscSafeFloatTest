#ifndef gscBoost_safeFloat_tupleToVector_h
#define gscBoost_safeFloat_tupleToVector_h

#include <tuple>
#include <vector>

namespace gscBoost {
namespace safeFloat {

namespace detail {

template <class Tuple, std::size_t N>
struct TupleElementToVectorImpl
{
  static auto build( const std::size_t size, const Tuple& tuple )
  {
    return std::tuple_cat(
      TupleElementToVectorImpl<Tuple, N-1>::build( size, tuple ),
      std::make_tuple( std::vector( size, std::get<N-1>( tuple ) ) ) );
  }
};

template <class Tuple>
struct TupleElementToVectorImpl<Tuple, 1>
{
  static auto build( const std::size_t size, const Tuple& tuple )
  {
    return std::make_tuple( std::vector( size, std::get<0>( tuple ) ) );
  }
};

template <class Tuple>
struct TupleElementToVectorImpl<Tuple, 0>
{
  static auto build( const std::size_t, const Tuple& )
  {
    return std::make_tuple();
  }
};

} // namespace detail

template <class... Elements>
auto toTupleOfVectors( const std::size_t size, const std::tuple<Elements...>& tuple )
{
  return detail::TupleElementToVectorImpl<decltype( tuple ), sizeof... ( Elements )>::build( size, tuple );
}

} // namespace safeFloat
} // namespace gscBoost

#endif // gscBoost_safeFloat_tupleToVector_h
