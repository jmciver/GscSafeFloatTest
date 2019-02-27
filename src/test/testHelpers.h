#ifndef gsc_boost_safeFloat_test_testHelpers_h
#define gsc_boost_safeFloat_test_testHelpers_h

#include <tupleUtilities.h>

#include <tuple>
#include <sstream>

template <class... Args>
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

#endif // #ifndef gsc_boost_safeFloat_test_testHelpers_h
