#ifndef gsc_boost_safeFloat_tupleGetVector_h
#define gsc_boost_safeFloat_tupleGetVector_h

#include <tuple>
#include <vector>

template <std::size_t Index, class... Types>
typename std::vector<
  typename std::tuple_element<Index, std::tuple<Types...>>::type::value_type >&
  getVector( std::tuple<Types...>& tuple )
{
  return std::get<Index>( tuple );
}

#endif // gsc_boost_safeFloat_tupleGetVector_h
