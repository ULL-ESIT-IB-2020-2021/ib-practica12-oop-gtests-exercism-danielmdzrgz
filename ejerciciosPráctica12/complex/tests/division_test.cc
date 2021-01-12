#include <gtest/gtest.h>

#include "../src/complex.h"

TEST(DivisionTest, positives) {
  Complex complex_1(4,7);
  Complex complex_2(10,10);

  Complex division = division.divideComplex(complex_1, complex_2);
  Complex test(0.55,0.15);
  EXPECT_EQ(test, division);
}

TEST(DivisionTest, negatives) {
  Complex complex_1(-4,-7);
  Complex complex_2(-10,-10);

  Complex division = division.divideComplex(complex_1, complex_2);
  Complex test(0.55,0.15);
  EXPECT_EQ(test, division);
}

TEST(DivisionTest, mix) {
  Complex complex_1(4,-7);
  Complex complex_2(-10,10);

  Complex division = division.divideComplex(complex_1, complex_2);
  Complex test(-0.55,0.15);
  EXPECT_EQ(test, division);
}