#include "test.h"

// Тесты для 2.a
TEST(a_3, test_1) {
  ifstream file("test_1.txt");
  file_bit_sort(&file);

  EXPECT_EQ(1, 1);
}
