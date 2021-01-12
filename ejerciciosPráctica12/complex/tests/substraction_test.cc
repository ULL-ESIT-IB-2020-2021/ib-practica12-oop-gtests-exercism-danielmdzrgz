#include <gtest/gtest.h>

#include "../src/complex.h"

TEST(SubstractionTest, positives) {
  Complex complex_1(4,5);
  Complex complex_2(3,10);

  Complex substraction = substraction.substractComp(complex_1, complex_2);
  Complex test(1,-5);
  EXPECT_EQ(test, substraction);
}

TEST(SubstractionTest, negatives) {
  Complex complex_1(-4,-5);
  Complex complex_2(-3,-10);

  Complex substraction = substraction.substractComp(complex_1, complex_2);
  Complex test(-1,5);
  EXPECT_EQ(test, substraction);
}

TEST(SubstractionTest, mix) {
  Complex complex_1(4,-5);
  Complex complex_2(-3,10);

  Complex substraction = substraction.substractComp(complex_1, complex_2);
  Complex test(7,-15);
  EXPECT_EQ(test, substraction);
}