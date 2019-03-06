#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <cmath>
#include <stdexcept>

constexpr float checkedConversionToFloat( const long double value )
{
  const auto valueAsFloat { static_cast<float>( value ) };
  return std::isinf( valueAsFloat ) ?
    throw std::logic_error( "value of type long double cannot be converted to type float" ) :
    valueAsFloat;
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

/// @brief The following literal, "_pip0p5", stands for (p)ositive (i)nteger
///   (p)ower of 0.5.
constexpr float operator"" _pip0p5( const long double value )
{
  const auto valueAsFloat { checkedConversionToFloat( value ) };
  return isIntegerPowerOfBase( valueAsFloat, 0.5f ) ?
    valueAsFloat :
    throw std::logic_error( "value is not integer power of 0.5f" );
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
