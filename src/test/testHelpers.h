#ifndef gscBoost_safeFloat_test_testHelpers_h
#define gscBoost_safeFloat_test_testHelpers_h

#include <tupleUtilities.h>

#include <tuple>
#include <sstream>

template <class... Elements>
bool operator== ( const std::string& lhs, const std::tuple<Elements...>& rhs )
{
  std::ostringstream stream;
  stream << rhs;
  return lhs.compare( stream.str() ) == 0 ? true : false;
}

#endif // #ifndef gscBoost_safeFloat_test_testHelpers_h
