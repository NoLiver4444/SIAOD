#include "test.h"

// Тесты для 2.a
TEST(a_2, test_1) {
  unsigned char answ = 237;
  vector<int> vect = {1, 0, 5, 7, 2, 4};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_8_bit_kit(code_answ, 8);
}

TEST(a_2, test_2) {
  unsigned char answ = 255;
  vector<int> vect = {1, 7, 5, 4, 3, 2, 4, 6, 2, 0};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_8_bit_kit(code_answ, 8);
}

TEST(a_2, test_3) {
  unsigned char answ = 90;
  vector<int> vect = {3, 4, 4, 4, 1, 6};

  unsigned char code_answ = sort_8_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_8_bit_kit(code_answ, 8);
}

// Тесты для 2.б
TEST(b_2, test_1) {
  unsigned long long answ = 17079902686316397056ULL;
  ;
  vector<int> vect = {1, 0, 5, 7, 2, 4, 23, 54, 12, 42, 47};

  unsigned long long code_answ = sort_64_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_64_bit_kit(code_answ, 64);
}

TEST(b_2, test_2) {
  unsigned long long answ = 18376939378996937728ULL;
  vector<int> vect = {1, 7, 5, 4, 3, 2, 4, 6, 2, 0, 23, 53, 12};

  unsigned long long code_answ = sort_64_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_64_bit_kit(code_answ, 64);
}

TEST(b_2, test_3) {
  unsigned long long answ = 6485466040050384896ULL;
  vector<int> vect = {3, 4, 4, 4, 1, 6, 43, 23, 15, 32};

  unsigned long long code_answ = sort_64_bit_kit(vect);

  EXPECT_EQ(answ, code_answ);
  print_64_bit_kit(code_answ, 64);
}