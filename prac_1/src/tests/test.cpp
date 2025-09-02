#include "test.h"

// Тесты для 1.a
TEST(a_1, test_1) { EXPECT_EQ(bit_mask(255, 1, 4), 239); }

TEST(a_1, test_2) { EXPECT_EQ(bit_mask(154, 1, 4), 138); }

TEST(a_1, test_3) { EXPECT_EQ(bit_mask(73, 1, 4), 73); }

// Тесты для 1.б
TEST(b_1, test_1) { EXPECT_EQ(bit_mask(255, 1, 7), 127); }

TEST(b_1, test_2) { EXPECT_EQ(bit_mask(154, 1, 7), 26); }

TEST(b_1, test_3) { EXPECT_EQ(bit_mask(73, 1, 7), 73); }

// Доп тесты
TEST(bit_mask, one_bit_maska_1) { EXPECT_EQ(bit_mask(255, 1, 0), 254); }

TEST(bit_mask, one_bit_maska_2) { EXPECT_EQ(bit_mask(255, 1, 3), 247); }

TEST(bit_mask, one_bit_maska_3) { EXPECT_EQ(bit_mask(255, 1, 6), 191); }