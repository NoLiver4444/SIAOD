#include "test.h"

#include "help.h"

// Тесты для 3.a и 3.б
TEST(a_3, test_1) {
  ofstream create_file("test_file/tests/test_1.txt");
  ofstream answ_file("test_file/answ/test_1_answ.txt");

  create_random_values_file(3000000, 4534167, create_file, answ_file);

  create_file.close();
  answ_file.close();

  ifstream read_file("test_file/tests/test_1.txt");

  file_bit_sort(read_file, "test_file/code_answ/test_1_code_answer.txt");

  read_file.close();

  ifstream answ("test_file/answ/test_1_answ.txt");
  ifstream code_answ("test_file/code_answ/test_1_code_answer.txt");

  EXPECT_TRUE(check_files(answ, code_answ));

  answ.close();
  code_answ.close();
}

TEST(a_3, test_2) {
  ofstream create_file("test_file/tests/test_2.txt");
  ofstream answ_file("test_file/answ/test_2_answ.txt");

  create_random_values_file(1000000, 5347198, create_file, answ_file);

  create_file.close();
  answ_file.close();

  ifstream read_file("test_file/tests/test_2.txt");

  file_bit_sort(read_file, "test_file/code_answ/test_2_code_answer.txt");

  read_file.close();

  ifstream answ("test_file/answ/test_2_answ.txt");
  ifstream code_answ("test_file/code_answ/test_2_code_answer.txt");

  EXPECT_TRUE(check_files(answ, code_answ));

  answ.close();
  code_answ.close();
}

TEST(a_3, test_3) {
  ofstream create_file("test_file/tests/test_3.txt");
  ofstream answ_file("test_file/answ/test_3_answ.txt");

  create_random_values_file(1000000, 9999999, create_file, answ_file);

  create_file.close();
  answ_file.close();

  ifstream read_file("test_file/tests/test_3.txt");

  file_bit_sort(read_file, "test_file/code_answ/test_3_code_answer.txt");

  read_file.close();

  ifstream answ("test_file/answ/test_3_answ.txt");
  ifstream code_answ("test_file/code_answ/test_3_code_answer.txt");

  EXPECT_TRUE(check_files(answ, code_answ));

  answ.close();
  code_answ.close();
}