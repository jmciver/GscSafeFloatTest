#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestPositiveIntegerPowerLiteral
#include <boost/test/unit_test.hpp>

#include <positiveIntegerPowerLiteral.h>

#include <cfenv>
#include <cmath>
#include <limits>

using namespace gscBoost::safeFloat;

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
  constexpr float value20 = 0.00000095367431640625_pip0p5;
  constexpr float value21 = 0.000000476837158203125_pip0p5;
  constexpr float value22 = 0.0000002384185791015625_pip0p5;
  constexpr float value23 = 0.00000011920928955078125_pip0p5;
  constexpr float value24 = 0.000000059604644775390625_pip0p5;
  constexpr float value25 = 0.0000000298023223876953125_pip0p5;
  constexpr float value26 = 0.00000001490116119384765625_pip0p5;
  constexpr float value27 = 0.000000007450580596923828125_pip0p5;
  constexpr float value28 = 0.0000000037252902984619140625_pip0p5;
  constexpr float value29 = 0.00000000186264514923095703125_pip0p5;
  constexpr float value30 = 0.000000000931322574615478515625_pip0p5;
  constexpr float value31 = 0.0000000004656612873077392578125_pip0p5;
  constexpr float value32 = 0.00000000023283064365386962890625_pip0p5;
  constexpr float value33 = 0.000000000116415321826934814453125_pip0p5;
  constexpr float value34 = 0.0000000000582076609134674072265625_pip0p5;
  constexpr float value35 = 0.00000000002910383045673370361328125_pip0p5;
  constexpr float value36 = 0.000000000014551915228366851806640625_pip0p5;
  constexpr float value37 = 0.0000000000072759576141834259033203125_pip0p5;
  constexpr float value38 = 0.00000000000363797880709171295166015625_pip0p5;
  constexpr float value39 = 0.000000000001818989403545856475830078125_pip0p5;
  constexpr float value40 = 0.0000000000009094947017729282379150390625_pip0p5;
  constexpr float value41 = 0.0000000000004547473508864641189575195312_pip0p5;
  constexpr float value42 = 0.0000000000002273736754432320594787597656_pip0p5;
  constexpr float value43 = 0.0000000000001136868377216160297393798828_pip0p5;
  constexpr float value44 = 0.00000000000005684341886080801486968994141_pip0p5;
  constexpr float value45 = 0.00000000000002842170943040400743484497070_pip0p5;
  constexpr float value46 = 0.00000000000001421085471520200371742248535_pip0p5;
  constexpr float value47 = 0.000000000000007105427357601001858711242676_pip0p5;
  constexpr float value48 = 0.000000000000003552713678800500929355621338_pip0p5;
  constexpr float value49 = 0.000000000000001776356839400250464677810669_pip0p5;
  constexpr float value50 = 0.0000000000000008881784197001252323389053345_pip0p5;
  constexpr float value51 = 0.0000000000000004440892098500626161694526672_pip0p5;
  constexpr float value52 = 0.0000000000000002220446049250313080847263336_pip0p5;
  constexpr float value53 = 0.0000000000000001110223024625156540423631668_pip0p5;
  constexpr float value54 = 0.00000000000000005551115123125782702118158340_pip0p5;
  constexpr float value55 = 0.00000000000000002775557561562891351059079170_pip0p5;
  constexpr float value56 = 0.00000000000000001387778780781445675529539585_pip0p5;
  constexpr float value57 = 0.000000000000000006938893903907228377647697926_pip0p5;
  constexpr float value58 = 0.000000000000000003469446951953614188823848963_pip0p5;
  constexpr float value59 = 0.000000000000000001734723475976807094411924481_pip0p5;
  constexpr float value60 = 0.0000000000000000008673617379884035472059622407_pip0p5;
  constexpr float value61 = 0.0000000000000000004336808689942017736029811203_pip0p5;
  constexpr float value62 = 0.0000000000000000002168404344971008868014905602_pip0p5;
  constexpr float value63 = 0.0000000000000000001084202172485504434007452801_pip0p5;
  constexpr float value64 = 0.00000000000000000005421010862427522170037264004_pip0p5;
  constexpr float value65 = 0.00000000000000000002710505431213761085018632002_pip0p5;
  constexpr float value66 = 0.00000000000000000001355252715606880542509316001_pip0p5;
  constexpr float value67 = 0.000000000000000000006776263578034402712546580005_pip0p5;
  constexpr float value68 = 0.000000000000000000003388131789017201356273290003_pip0p5;
  constexpr float value69 = 0.000000000000000000001694065894508600678136645001_pip0p5;
  constexpr float value70 = 0.0000000000000000000008470329472543003390683225007_pip0p5;
  constexpr float value71 = 0.0000000000000000000004235164736271501695341612503_pip0p5;
  constexpr float value72 = 0.0000000000000000000002117582368135750847670806252_pip0p5;
  constexpr float value73 = 0.0000000000000000000001058791184067875423835403126_pip0p5;
  constexpr float value74 = 0.00000000000000000000005293955920339377119177015629_pip0p5;
  constexpr float value75 = 0.00000000000000000000002646977960169688559588507815_pip0p5;
  constexpr float value76 = 0.00000000000000000000001323488980084844279794253907_pip0p5;
  constexpr float value77 = 0.000000000000000000000006617444900424221398971269537_pip0p5;
  constexpr float value78 = 0.000000000000000000000003308722450212110699485634768_pip0p5;
  constexpr float value79 = 0.000000000000000000000001654361225106055349742817384_pip0p5;
  constexpr float value80 = 0.0000000000000000000000008271806125530276748714086921_pip0p5;
  constexpr float value81 = 0.0000000000000000000000004135903062765138374357043460_pip0p5;
  constexpr float value82 = 0.0000000000000000000000002067951531382569187178521730_pip0p5;
  constexpr float value83 = 0.0000000000000000000000001033975765691284593589260865_pip0p5;
  constexpr float value84 = 0.00000000000000000000000005169878828456422967946304325_pip0p5;
  constexpr float value85 = 0.00000000000000000000000002584939414228211483973152163_pip0p5;
  constexpr float value86 = 0.00000000000000000000000001292469707114105741986576081_pip0p5;
  constexpr float value87 = 0.000000000000000000000000006462348535570528709932880407_pip0p5;
  constexpr float value88 = 0.000000000000000000000000003231174267785264354966440203_pip0p5;
  constexpr float value89 = 0.000000000000000000000000001615587133892632177483220102_pip0p5;
  constexpr float value90 = 0.0000000000000000000000000008077935669463160887416100508_pip0p5;
  constexpr float value91 = 0.0000000000000000000000000004038967834731580443708050254_pip0p5;
  constexpr float value92 = 0.0000000000000000000000000002019483917365790221854025127_pip0p5;
  constexpr float value93 = 0.0000000000000000000000000001009741958682895110927012564_pip0p5;
  constexpr float value94 = 0.00000000000000000000000000005048709793414475554635062818_pip0p5;
  constexpr float value95 = 0.00000000000000000000000000002524354896707237777317531409_pip0p5;
  constexpr float value96 = 0.00000000000000000000000000001262177448353618888658765704_pip0p5;
  constexpr float value97 = 0.000000000000000000000000000006310887241768094443293828522_pip0p5;
  constexpr float value98 = 0.000000000000000000000000000003155443620884047221646914261_pip0p5;
  constexpr float value99 = 0.000000000000000000000000000001577721810442023610823457131_pip0p5;
  constexpr float value100 = 0.0000000000000000000000000000007888609052210118054117285653_pip0p5;
  constexpr float value101 = 0.0000000000000000000000000000003944304526105059027058642826_pip0p5;
  constexpr float value102 = 0.0000000000000000000000000000001972152263052529513529321413_pip0p5;
  constexpr float value103 = 0.00000000000000000000000000000009860761315262647567646607066_pip0p5;
  constexpr float value104 = 0.00000000000000000000000000000004930380657631323783823303533_pip0p5;
  constexpr float value105 = 0.00000000000000000000000000000002465190328815661891911651767_pip0p5;
  constexpr float value106 = 0.00000000000000000000000000000001232595164407830945955825883_pip0p5;
  constexpr float value107 = 0.000000000000000000000000000000006162975822039154729779129416_pip0p5;
  constexpr float value108 = 0.000000000000000000000000000000003081487911019577364889564708_pip0p5;
  constexpr float value109 = 0.000000000000000000000000000000001540743955509788682444782354_pip0p5;
  constexpr float value110 = 0.0000000000000000000000000000000007703719777548943412223911770_pip0p5;
  constexpr float value111 = 0.0000000000000000000000000000000003851859888774471706111955885_pip0p5;
  constexpr float value112 = 0.0000000000000000000000000000000001925929944387235853055977943_pip0p5;
  constexpr float value113 = 0.00000000000000000000000000000000009629649721936179265279889713_pip0p5;
  constexpr float value114 = 0.00000000000000000000000000000000004814824860968089632639944856_pip0p5;
  constexpr float value115 = 0.00000000000000000000000000000000002407412430484044816319972428_pip0p5;
  constexpr float value116 = 0.00000000000000000000000000000000001203706215242022408159986214_pip0p5;
  constexpr float value117 = 0.000000000000000000000000000000000006018531076210112040799931071_pip0p5;
  constexpr float value118 = 0.000000000000000000000000000000000003009265538105056020399965535_pip0p5;
  constexpr float value119 = 0.000000000000000000000000000000000001504632769052528010199982768_pip0p5;
  constexpr float value120 = 0.0000000000000000000000000000000000007523163845262640050999913838_pip0p5;
  constexpr float value121 = 0.0000000000000000000000000000000000003761581922631320025499956919_pip0p5;
  constexpr float value122 = 0.0000000000000000000000000000000000001880790961315660012749978460_pip0p5;
  constexpr float value123 = 0.00000000000000000000000000000000000009403954806578300063749892298_pip0p5;
  constexpr float value124 = 0.00000000000000000000000000000000000004701977403289150031874946149_pip0p5;
  constexpr float value125 = 0.00000000000000000000000000000000000002350988701644575015937473074_pip0p5;
  constexpr float value126 = 0.00000000000000000000000000000000000001175494350822287507968736537_pip0p5;

  const float sum { value1 + value2 + value3 + value4 + value5 + value6 +
    value7 + value8 + value9 + value10 + value11 + value12 + value13 + value14 +
    value15 + value16 + value17 + value18 + value19 + value20 + value21 + value22 +
    value23 + value24 + value25 + value26 + value27 + value28 + value29 +
    value30 + value31 + value32 + value33 + value34 + value35 + value36 + value37 +
    value38 + value39 + value40 + value41 + value42 + value43 + value44 +
    value45 + value46 + value47 + value48 + value49 + value50 + value51 + value52 +
    value53 + value54 + value55 + value56 + value57 + value58 + value59 +
    value60 + value61 + value62 + value63 + value64 + value65 + value66 + value67 +
    value68 + value69 + value70 + value71 + value72 + value73 + value74 +
    value75 + value76 + value77 + value78 + value79 + value80 + value81 + value82 +
    value83 + value84 + value85 + value86 + value87 + value88 + value89 +
    value90 + value91 + value92 + value93 + value94 + value95 + value96 + value97 +
    value98 + value99 + value100 + value101 + value102 + value103 + value104 +
    value105 + value106 + value107 + value108 + value109 + value110 + value111 +
    value112 + value113 + value114 + value115 + value116 + value117 + value118 +
    value119 + value120 + value121 + value122 + value123 + value124 + value125 +
    value126 };

  BOOST_CHECK( sum > 0.0f );
}

BOOST_AUTO_TEST_CASE( testDetectionOfNonNormal )
{
  float value127 { 1.0f };
  BOOST_CHECK_THROW(
    value127 = 0.000000000000000000000000000000000000005877471754111437539843682686_pip0p5,
    std::logic_error );
  BOOST_CHECK_EQUAL( 1.0f, value127 );
}

BOOST_AUTO_TEST_CASE( testCastingFromLongDoubleToFloat )
{
  constexpr float value1 = detail::checkedConversionToFloat( std::numeric_limits<float>::max() );
  BOOST_CHECK( value1 > 0.0f );
  constexpr float value2 = detail::checkedConversionToFloat( -std::numeric_limits<float>::max() );
  BOOST_CHECK( value2 < 0.0f );
  constexpr float value3 = detail::checkedConversionToFloat( std::numeric_limits<float>::min() );
  BOOST_CHECK( value3 > 0.0f );
  constexpr float value4 = detail::checkedConversionToFloat( -std::numeric_limits<float>::min() );
  BOOST_CHECK( value4 < 0.0f );
}

BOOST_AUTO_TEST_CASE( testCastingDetectionOfOverflow )
{
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( std::numeric_limits<long double>::max() ),
    std::logic_error );
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( -std::numeric_limits<long double>::max() ),
    std::logic_error );
}

BOOST_AUTO_TEST_CASE( testCastingDetectionOfUnderflow )
{
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( std::numeric_limits<long double>::min() ),
    std::logic_error );
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( -std::numeric_limits<long double>::min() ),
    std::logic_error );
}

BOOST_AUTO_TEST_CASE( testCastingOfNanAndInf )
{
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( std::numeric_limits<long double>::quiet_NaN() ),
    std::logic_error );
  BOOST_CHECK_THROW(
    detail::checkedConversionToFloat( std::numeric_limits<long double>::infinity() ),
    std::logic_error );
}

BOOST_AUTO_TEST_CASE( testIntegerPowerOf0p5UsingNanAndInf )
{
  BOOST_CHECK_THROW(
    detail::integerPowerOf0p5( std::numeric_limits<float>::quiet_NaN() ),
    std::logic_error );
  BOOST_CHECK_THROW(
    detail::integerPowerOf0p5( std::numeric_limits<float>::infinity() ),
    std::logic_error );
}
