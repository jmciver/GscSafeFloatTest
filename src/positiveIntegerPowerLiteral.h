#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <cmath>
#include <limits>
#include <stdexcept>

constexpr bool isInRangeOfFloat( const long double value )
{
  const auto absoluteValue { std::abs( value ) };
  return
    static_cast<long double>( std::numeric_limits<float>::max() ) >= absoluteValue &&
    static_cast<long double>( std::numeric_limits<float>::min() ) <= absoluteValue;
}

constexpr float checkedConversionToFloat( const long double value )
{
  return isInRangeOfFloat( value ) ?
    static_cast<float>( value ) :
    throw std::logic_error( "the value of type long double cannot be converted to type float" );
}

constexpr float power( const float base, const int exponent )
{
  return std::pow( base, static_cast<float>( exponent ) );
}

constexpr bool isIntegerPowerOfBase( const float value, const float base )
{
  auto exponent { 1 };
  auto result { power( base, exponent ) };
  while ( std::isnormal( result ) ) {
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
    throw std::logic_error( "value is not integer power of 0.5f" );
}

/// @brief The following literal, "_pip0p5", stands for (p)ositive (i)nteger
///   (p)ower of 0.5.
constexpr float operator"" _pip0p5( const long double value )
{
  return integerPowerOf0p5( checkedConversionToFloat( value ) );
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
