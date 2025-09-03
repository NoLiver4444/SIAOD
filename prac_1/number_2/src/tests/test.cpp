#include "test.h"

// Тесты для 2.a
TEST(a_2, test_1) {
  unsigned char answ = 237;
  vector<int> vect = {1, 0, 5, 7, 2, 4};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}

TEST(a_2, test_2) {
  unsigned char answ = 255;
  vector<int> vect = {1, 7, 5, 4, 3, 2, 4, 6, 2, 0};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}

TEST(a_2, test_3) {
  unsigned char answ = 90;
  vector<int> vect = {3, 4, 4, 4, 1, 6};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}


// Тесты для 2.б
TEST(b_2, test_1) {
  unsigned char answ = 237;
  vector<int> vect = {1, 0, 5, 7, 2, 4};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}

TEST(b_2, test_2) {
  unsigned char answ = 255;
  vector<int> vect = {1, 7, 5, 4, 3, 2, 4, 6, 2, 0};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}

TEST(b_2, test_3) {
  unsigned char answ = 90;
  vector<int> vect = {3, 4, 4, 4, 1, 6};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_bit_kit(code_answ, 8);
}