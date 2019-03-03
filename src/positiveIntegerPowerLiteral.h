#ifndef gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
#define gsc_boost_safeFloat_positiveIntegerPowerLiteral_h

#include <cfenv>
#include <cmath>

static const float kPositivePowerInteger { 0.5f };

template <typename T>
struct PositivePowerIntegerImpl;

template <float Value>
struct PositivePowerIntegerImpl<Value>
{
  using value = Value;
};

template <typename Value>
float operator"" _ppi()
{
  retun PositivePowerIntegerImpl<Value>::value;
}

#endif // gsc_boost_safeFloat_positiveIntegerPowerLiteral_h
