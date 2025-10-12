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

TEST(plagiat_check, empty_line) {
  RabinKarpPlagiarismChecker checker;

  std::string original9 = "Обычный текст";
  std::string suspected9 = "";

  EXPECT_EQ(false, checker.checkPlagiarism(original9, suspected9, 5));
}

TEST(plagiat_check, plagiat_yes) {
  RabinKarpPlagiarismChecker checker;

    std::string original1 =
      "Этот текст содержит уникальные идеи и оригинальные формулировки для "
      "проверки системы";
    std::string suspected1 =
      "Этот текст содержит уникальные идеи и оригинальные формулировки для ";

  EXPECT_EQ(true, checker.checkPlagiarism(original1, suspected1, 5));
}

TEST(plagiat_check, plagiat_no) {
  RabinKarpPlagiarismChecker checker;

    std::string original1 =
      "qwer";
    std::string suspected1 =
      "Этот текст содержит уникальные идеи и оригинальные формулировки для ";

  EXPECT_EQ(false, checker.checkPlagiarism(original1, suspected1, 5));
}