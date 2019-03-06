#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <boost/numeric/conversion/cast.hpp>

#include <cfenv>
#include <cmath>
#include <iostream>
#include <limits>

constexpr const float kPositivePowerInteger { 0.5f };

constexpr float checkedConversionToFloat( long double value )
{
  const float valueAsFloat { static_cast<float>( value ) };
  return std::isinf( valueAsFloat ) ?
    throw std::logic_error( "value of type long double cannot be converted to type float" ) :
    valueAsFloat;
}

constexpr float oneHalfRaisedTo( int exponent )
{
  return std::pow( kPositivePowerInteger, static_cast<float>( exponent ) );
}

constexpr bool isIntegerPowerOfOneHalf( const float value )
{
  int power { 1 };
  float powerOf0p5 { oneHalfRaisedTo( power ) };
  while ( std::isnormal( powerOf0p5 ) ) {
    if ( powerOf0p5 == value ) {
      return true;
    }
    powerOf0p5 = oneHalfRaisedTo( ++power );
  }
  return false;
}

constexpr float operator"" _pip0p5( long double dividend )
{
  float dividendAsFloat { checkedConversionToFloat( dividend ) };
  return isIntegerPowerOfOneHalf( dividendAsFloat ) ?
    dividendAsFloat :
    throw std::logic_error( "value is not integer power of 0.5f" );
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
