#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <boost/numeric/conversion/cast.hpp>

#include <cfenv>
#include <cmath>
#include <iostream>
#include <limits>

constexpr const float kPositivePowerInteger { 0.5f };

constexpr bool isInRangeOfFloat( long double value )
{
  const auto floatMax { static_cast<long double>( std::numeric_limits<float>::max() ) };
  const auto floatMin { static_cast<long double>( std::numeric_limits<float>::min() ) };
  return floatMax >= value && value >= floatMin ? true : false;
}

constexpr float checkedConversionToFloat( long double value )
{
  if ( ! isInRangeOfFloat( value ) ) {
     throw std::logic_error( "value cannot be represented as a float" );
  }
  return static_cast<float>( value );
}

constexpr float halfRaisedTo( int exponent )
{
  std::feclearexcept( FE_ALL_EXCEPT );
  return std::pow( kPositivePowerInteger, static_cast<float>( exponent ) );
}

constexpr bool isDivisableByPowerOfHalf( const float dividend )
{
  int power { 1 };
  float divisor { halfRaisedTo( power ) };
  while ( ! std::fetestexcept( FE_UNDERFLOW ) ) {
    if ( std::fmod( dividend, divisor ) == 0.0f ) {
      return true;
    }
    divisor = halfRaisedTo( ++power );
  }
  return false;
}

constexpr float operator"" _pipl( long double dividend )
{
  float dividendAsFloat { checkedConversionToFloat( dividend ) };
  if ( ! isDivisableByPowerOfHalf( dividendAsFloat ) ) {
    throw std::logic_error( "dividend is not divisable by 0.5f to an integer power" );
  }
  return dividendAsFloat;
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
