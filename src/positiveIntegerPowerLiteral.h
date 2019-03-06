#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <boost/numeric/conversion/cast.hpp>

#include <cfenv>
#include <cmath>
#include <iostream>
#include <limits>

constexpr float kBase { 0.5f };

constexpr float checkedConversionToFloat( long double value )
{
  const auto valueAsFloat { static_cast<float>( value ) };
  return std::isinf( valueAsFloat ) ?
    throw std::logic_error( "value of type long double cannot be converted to type float" ) :
    valueAsFloat;
}

constexpr float raiseBaseTo( int exponent )
{
  return std::pow( kBase, static_cast<float>( exponent ) );
}

constexpr bool isIntegerPowerOfBase( const float value )
{
  auto power { 1 };
  auto powerOf0p5 { raiseBaseTo( power ) };
  while ( std::isnormal( powerOf0p5 ) ) {
    if ( powerOf0p5 == value ) {
      return true;
    }
    powerOf0p5 = raiseBaseTo( ++power );
  }
  return false;
}

constexpr float operator"" _pip0p5( long double value )
{
  const auto valueAsFloat { checkedConversionToFloat( value ) };
  return isIntegerPowerOfBase( valueAsFloat ) ?
    valueAsFloat :
    throw std::logic_error( "value is not integer power of 0.5f" );
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
