#include "test.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

TEST(word_count, one_word) {
  std::string line = "qwer, gfdsfgdsa fdsahfiudsah uhduis";

  StringData data(line);

  EXPECT_EQ(1, data.countWord());
}

TEST(word_count, two_word) {
  std::string line = "qwer, gfdsfgdsa qwer. fdsahfiudsah uhduis";

  StringData data(line);

  EXPECT_EQ(2, data.countWord());
}

TEST(word_count, three_word) {
  std::string line =
      "qwer, gfdsfgdsa qwer. fdsahfiudsah, qwer uhduis qwerfdsfsd";

  StringData data(line);

  EXPECT_EQ(3, data.countWord());
}

TEST(word_count, upper_word) {
  std::string line = "Qwer, gfdsfgdsa qwer. fdsahfiudsah, qwer uhduis QWER";

  StringData data(line);

  EXPECT_EQ(4, data.countWord());
}