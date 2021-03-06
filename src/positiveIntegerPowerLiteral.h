// File: positiveIntegerPowerLiteral.h
// Description: Implementation of programming competency test 1 of 3.

#ifndef gscBoost_safeFloat_positiveIntegerPowerLiteral_h
#define gscBoost_safeFloat_positiveIntegerPowerLiteral_h

#include <cmath>
#include <limits>
#include <stdexcept>

namespace gscBoost {
namespace safeFloat {

namespace detail {

constexpr bool isInRangeOfFloat( const long double value )
{
#if defined(_MSC_VER)
  const auto absoluteValue { value < 0 ? -value : value };
#else
  const auto absoluteValue { std::abs( value ) };
#endif
  return
    static_cast<long double>( std::numeric_limits<float>::max() ) >=
    absoluteValue &&
    static_cast<long double>( std::numeric_limits<float>::min() ) <=
    absoluteValue;
}

constexpr float checkedConversionToFloat( const long double value )
{
  return isInRangeOfFloat( value ) ?
    static_cast<float>( value ) :
    throw std::logic_error(
      "the value of type long double cannot be converted to"
      " type float" );
}

constexpr float power( const float base, const int exponent )
{
#if defined(_MSC_VER)
  // std::pow cannot be used in MSVC 14.1 as it is not delimited as constexpr.
  return exponent == 0 ? 1.0f : base * power(base, exponent - 1);
#else
  return std::pow( base, static_cast<float>( exponent ) );
#endif
}

constexpr bool isIntegerPowerOfBase(
  const float value,
  const float base )
{
  auto exponent { 1 };
  auto result { power( base, exponent ) };
#if defined(_MSC_VER)
  for( int i = 0; i < 127; ++i ) {
#else
  while (std::isnormal(result)) {
#endif
    if ( result == value ) {
      return true;
    }
    result = power( base, ++exponent );
  }
  return false;
}

constexpr float integerPowerOf0p5( const float value )
{
  return isIntegerPowerOfBase( value, 0.5f ) ?
    value :
    throw std::logic_error( "value is not an integer power of 0.5f" );
}

} // namespace detail

/// @brief Implementation of programming competency test 1 of 3.
///   The following literal, "_pip0p5", stands for (p)ositive
///   (i)nteger (p)ower of 0.5.
constexpr float operator"" _pip0p5( const long double value )
{
  return detail::integerPowerOf0p5( detail::checkedConversionToFloat( value ) );
}

} // namespace safeFloat
} // namespace gscBoost

#endif // gscBoost_safeFloat_positiveIntegerPowerLiteral_h
