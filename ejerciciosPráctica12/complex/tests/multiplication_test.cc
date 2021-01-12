#include <gtest/gtest.h>

#include "../src/complex.h"

TEST(MultiplicationTest, positives) {
  Complex complex_1(2,5);
  Complex complex_2(1,6);

  Complex multiplication = multiplication.multiplyComp(complex_1, complex_2);
  Complex test(-28,17);
  EXPECT_EQ(test, multiplication);
}

TEST(MultiplicationTest, negatives) {
  Complex complex_1(-2,-5);
  Complex complex_2(-1,-6);

  Complex multiplication = multiplication.multiplyComp(complex_1, complex_2);
  Complex test(-28,17);
  EXPECT_EQ(test, multiplication);
}

TEST(MultiplicationTest, mix) {
  Complex complex_1(2,-5);
  Complex complex_2(-1,6);

  Complex multiplication = multiplication.multiplyComp(complex_1, complex_2);
  Complex test(28,17);
  EXPECT_EQ(test, multiplication);
}