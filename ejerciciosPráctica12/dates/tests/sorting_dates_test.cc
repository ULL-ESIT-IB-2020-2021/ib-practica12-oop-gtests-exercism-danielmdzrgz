#include <gtest/gtest.h>

#include "../src/dates.h"

TEST(SortingDatesTest, greater_than) {
  Date date_1{10,05,2060};
  Date date_2{21,10,2002};
  std::vector<Date> date_vector{date_1, date_2};
  std::sort(date_vector.begin(), date_vector.end());
  std::vector<Date> sorted_dates = date_vector;

  EXPECT_EQ(true, sorted_dates[0] < sorted_dates[1]);
}

TEST(SortingDatesTest, greater_than_close_dates) {
  Date date_1{20,10,2002};
  Date date_2{21,10,2002};
  std::vector<Date> date_vector{date_1, date_2};
  std::sort(date_vector.begin(), date_vector.end());
  std::vector<Date> sorted_dates = date_vector;

  EXPECT_EQ(true, sorted_dates[0] < sorted_dates[1]);
}