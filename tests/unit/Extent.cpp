
#include <gtest/gtest.h>
#include <tp/geom/Extent.h>

using namespace TP::geom;

// Normally we use TEST(TestSuiteName, TestCaseName)
// but Extent is a template generic, so we are using TYPED_TEST_P
// to test all versions of Extent
// Source Example: https://github.com/google/googletest/blob/main/googletest/samples/sample6_unittest.cc

template<class T>
class ExtentTest: public testing::Test {
    protected:
        ExtentTest() {};
        virtual ~ExtentTest() {};
};

typedef testing::Types<
    float,
    double,
    int8_t,
    uint8_t,
    int16_t,
    uint16_t,
    int32_t,
    uint32_t,
    int64_t,
    uint64_t
> ExtentTypes;

TYPED_TEST_SUITE(ExtentTest, ExtentTypes);

TYPED_TEST(ExtentTest, CanBuildWithNoParams) {
    Extent<TypeParam> extent;
    TypeParam inf = std::numeric_limits<TypeParam>::infinity();
    TypeParam neginf = -inf;

    TypeParam minx, miny, maxx, maxy;
    extent.get(minx, miny, maxx, maxy);

    EXPECT_TRUE(minx == inf);
    EXPECT_TRUE(miny == inf);
    EXPECT_TRUE(maxx == neginf);
    EXPECT_TRUE(maxy == neginf);
}

// TYPED_TEST(ExtentTest, CanBuildWithParams) {
//     TypeParam minx = (TypeParam)-1.0, miny = (TypeParam)-1.0, maxx = (TypeParam)1.0, maxy = (TypeParam)1.0;

//     Extent<TypeParam> extent(minx, miny, maxx, maxy);

//     TypeParam x1, y1, x2, y2;
//     extent.get(x1, y1, x2, y2);

//     EXPECT_TRUE(x1 == minx);
//     EXPECT_TRUE(y1 == miny);
//     EXPECT_TRUE(x2 == maxx);
//     EXPECT_TRUE(y2 == maxy);
// }
