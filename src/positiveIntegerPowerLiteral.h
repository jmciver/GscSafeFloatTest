#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <boost/numeric/conversion/cast.hpp>

#include <cfenv>
#include <cmath>
#include <iostream>
#include <limits>

constexpr const float kPositivePowerInteger { 0.5f };

constexpr bool inRangeOfFloat( long double value )
{
  const auto floatMax { static_cast<long double>( std::numeric_limits<float>::max() ) };
  const auto floatMin { static_cast<long double>( std::numeric_limits<float>::min() ) };
  return floatMax >= value && value >= floatMin ? true : false;
}

constexpr float halfRaisedTo( int exponent )
{
  std::feclearexcept( FE_ALL_EXCEPT );
  return std::pow( kPositivePowerInteger, static_cast<float>( exponent ) );
}

constexpr bool isDivisableByPowerOfHalf( float dividend )
{
  int power { 1 };
  float divisor { halfRaisedTo( power ) };
  while ( ! std::fetestexcept( FE_UNDERFLOW ) ) {
    if ( std::fmod( divisor, dividend ) == 0.0f ) {
      return true;
    }
    divisor = halfRaisedTo( ++power );
  }
  return false;
}

constexpr float operator"" _pipl( long double value )
{
  if ( ! inRangeOfFloat( value ) ) {
    throw std::logic_error( "value cannot be represented as a float" );
  }
  std::feclearexcept( FE_ALL_EXCEPT );
  float valueAsFloat { static_cast<float>( value ) };
  float integral = 0.5f;
  if ( std::fmod( valueAsFloat, integral ) != 0.0f ) {
    throw std::logic_error( "value is not divisable by an integer power of 0.5f" );
  }
  return valueAsFloat;
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
