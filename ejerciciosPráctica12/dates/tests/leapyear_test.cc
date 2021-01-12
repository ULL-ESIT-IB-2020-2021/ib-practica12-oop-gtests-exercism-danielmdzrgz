#include <gtest/gtest.h>

#include "../src/dates.h"

TEST(LeapYearTest, is_leap_year) {
  std::string leap_year_test {"This is a leap year"};
  Date date{07,06,2020};
  std::string is_leap_year = date.leapYear();
  EXPECT_EQ(leap_year_test, is_leap_year);
}

TEST(LeapYearTest, not_leap_year) {
  std::string not_leap_year_test {"This is not a leap year"};
  Date date{17,06,1900};
  std::string is_leap_year = date.leapYear();
  EXPECT_EQ(not_leap_year_test, is_leap_year);
}