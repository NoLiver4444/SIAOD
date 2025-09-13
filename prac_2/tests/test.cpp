#include "test.h"

TEST(tests, test_1) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("answ/out.bin");

  UserInfo user1("qwer", "+7-916-254-76-23", "@qwer");
  UserInfo user2("asdf", "+7-456-632-81-28", "@asdf");

  binary_file_handler->input_to_file(user1);
  binary_file_handler->input_to_file(user2);

  binary_file_handler->output_from_file();

  delete binary_file_handler;
}

TEST(tests, test_2) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("answ/out.bin");

  UserInfo user1("qwer", "+7-916-254-76-23", "@qwer");
  UserInfo user2("asdf", "+7-456-632-81-28", "@asdf");
  UserInfo user3("zxcv", "+7-646-245-61-84", "@zxcv");

  binary_file_handler->input_to_file(user1);
  binary_file_handler->input_to_file(user2);
  binary_file_handler->input_to_file(user3);

  UserInfo answ = binary_file_handler->linear_search("+7-646-245-61-84");

  EXPECT_EQ("zxcv", answ.name);
  EXPECT_EQ("+7-646-245-61-84", answ.phone);
  EXPECT_EQ("@zxcv", answ.address);

  delete binary_file_handler;
}

TEST(tests, test_3) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("answ/out_1.bin");

  binary_file_handler->random_file(99);

  UserInfo user3("zxcv", "+9-999-999-99-99", "@zxcv");

  binary_file_handler->input_to_file(user3);

  UserInfo answ = binary_file_handler->linear_search("+9-999-999-99-99");

  EXPECT_EQ("zxcv", answ.name);
  EXPECT_EQ("+9-999-999-99-99", answ.phone);
  EXPECT_EQ("@zxcv", answ.address);

  binary_file_handler->binary_to_txt();

  delete binary_file_handler;
}

TEST(tests, test_4) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("answ/out_2.bin");

  binary_file_handler->random_file(999);

  UserInfo user3("zxcv", "+9-999-999-99-99", "@zxcv");

  binary_file_handler->input_to_file(user3);

  UserInfo answ = binary_file_handler->linear_search("+9-999-999-99-99");

  EXPECT_EQ("zxcv", answ.name);
  EXPECT_EQ("+9-999-999-99-99", answ.phone);
  EXPECT_EQ("@zxcv", answ.address);

  binary_file_handler->binary_to_txt();

  delete binary_file_handler;
}

TEST(tests, test_5) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("answ/out_3.bin");

  binary_file_handler->random_file(9999);

  UserInfo user3("zxcv", "+9-999-999-99-99", "@zxcv");

  binary_file_handler->input_to_file(user3);

  UserInfo answ = binary_file_handler->linear_search("+9-999-999-99-99");

  EXPECT_EQ("zxcv", answ.name);
  EXPECT_EQ("+9-999-999-99-99", answ.phone);
  EXPECT_EQ("@zxcv", answ.address);

  binary_file_handler->binary_to_txt();

  delete binary_file_handler;
}