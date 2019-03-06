#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestPositiveIntegerPowerLiteral
#include <boost/test/unit_test.hpp>

#include <positiveIntegerPowerLiteral.h>

#include <cfenv>
#include <cmath>
#include <limits>

BOOST_AUTO_TEST_CASE( testNonConstexpr )
{
  std::feclearexcept( FE_ALL_EXCEPT );
  auto result { std::pow( 0.5_pip0p5, 1.0f ) };
  if ( std::fetestexcept( FE_INEXACT ) ) {
    BOOST_CHECK( false );
  } else {
    BOOST_CHECK( result == 0.5f );
  }
}

BOOST_AUTO_TEST_CASE( testConstexpr )
{
  constexpr float value1 = 0.5_pip0p5;
  constexpr float value2 = 0.25_pip0p5;
  constexpr float value3 = 0.125_pip0p5;
  constexpr float value4 = 0.0625_pip0p5;
  constexpr float value5 = 0.03125_pip0p5;
  constexpr float value6 = 0.015625_pip0p5;
  constexpr float value7 = 0.0078125_pip0p5;
  constexpr float value8 = 0.00390625_pip0p5;
  constexpr float value9 = 0.001953125_pip0p5;
  constexpr float value10 = 0.0009765625_pip0p5;
  constexpr float value11 = 0.00048828125_pip0p5;
  constexpr float value12 = 0.000244140625_pip0p5;
  constexpr float value13 = 0.0001220703125_pip0p5;
  constexpr float value14 = 0.00006103515625_pip0p5;
  constexpr float value15 = 0.000030517578125_pip0p5;
  constexpr float value16 = 0.0000152587890625_pip0p5;
  constexpr float value17 = 0.00000762939453125_pip0p5;
  constexpr float value18 = 0.000003814697265625_pip0p5;
  constexpr float value19 = 0.0000019073486328125_pip0p5;
  float sum { value1 + value2 + value3 + value4 + value5 + value6 + value7 +
    value8 + value9 + value10 + value11 + value12 + value13 + value14 + value15 +
    value16 + value17 + value18 + value19 };
  BOOST_CHECK( sum > 0.0f );
}

BOOST_AUTO_TEST_CASE( testCastingFromLongDoubleToFloat )
{
  constexpr float value1 = checkedConversionToFloat( std::numeric_limits<float>::max() );
  BOOST_CHECK( value1 > 0.0f );
  constexpr float value2 = checkedConversionToFloat( -std::numeric_limits<float>::max() );
  BOOST_CHECK( value2 < 0.0f );
}
