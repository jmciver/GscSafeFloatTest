#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <boost/numeric/conversion/cast.hpp>

#include <cfenv>
#include <cmath>
#include <iostream>

static const float kPositivePowerInteger { 0.5f };

float operator"" _pipl(long double value)
{
  const float valueAsFloat { boost::numeric_cast<float>( value ) };
  return valueAsFloat;
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
