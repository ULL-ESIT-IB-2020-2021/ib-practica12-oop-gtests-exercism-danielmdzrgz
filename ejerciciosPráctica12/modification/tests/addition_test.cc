#include <gtest/gtest.h>

#include "../src/complex_mod.h"

TEST(AdditionTest, positives) {
  Complex complex_1(3,6);
  Complex complex_2(7,10);

  Complex addition = addition.addComp(complex_1, complex_2);
  Complex test(10,16);
  EXPECT_EQ(test, addition);
}

TEST(AdditionTest, negatives) {
  Complex complex_1(-3,-6);
  Complex complex_2(-7,-10);

  Complex addition = addition.addComp(complex_1, complex_2);
  Complex test(-10,-16);
  EXPECT_EQ(test, addition);
}

TEST(AdditionTest, mix) {
  Complex complex_1(3,-6);
  Complex complex_2(-7,10);

  Complex addition = addition.addComp(complex_1, complex_2);
  Complex test(-4,4);
  EXPECT_EQ(test, addition);
}