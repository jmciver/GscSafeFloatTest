#ifndef gsc_boost_safeFloat_tupleGetVector_h
#define gsc_boost_safeFloat_tupleGetVector_h

#include <type_traits>
#include <tuple>
#include <vector>

namespace gscBoost {
namespace safeFloat {

namespace detail {

template <class T>
struct IsVectorType
{
  using value = std::false_type;
};

template <class T>
struct IsVectorType<std::vector<T>>
{
  using value = std::true_type;
};

template <std::size_t Index>
struct CheckTupleOfVectorsImpl
{
  template <class... Elements>
  static void apply( const std::tuple<Elements...>& tuple )
  {
    static_assert(
      IsVectorType<typename std::tuple_element<Index - 1, std::tuple<Elements...>>::type>::value::value,
      "attempting to call getVector on tuple with non-vector type" );
    CheckTupleOfVectorsImpl<Index - 1>::apply( tuple );
  }
};

template <>
struct CheckTupleOfVectorsImpl<1>
{
  template <class... Elements>
  static void apply( const std::tuple<Elements...>& )
  {
    static_assert(
      IsVectorType<typename std::tuple_element<0, std::tuple<Elements...>>::type>::value::value,
      "attempting to call getVector on tuple with non-vector type" );
  }
};

} // namespace detail

template <std::size_t Index, class... Elements>
auto& getVector( std::tuple<Elements...>& tuple )
{
  static_assert(
    sizeof... ( Elements ) > 0,
    "attempting to call getVector using empty tuple" );
  detail::CheckTupleOfVectorsImpl<sizeof... ( Elements )>::apply( tuple );
  return std::get<Index>( tuple );
}

} // namespace safeFloat
} // namespace gscBoost

#endif // gsc_boost_safeFloat_tupleGetVector_h
