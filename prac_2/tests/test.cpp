#include "test.h"

TEST(tests, test_1) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("out.bin");

  UserInfo user1("qwer", "+7-916-254-76-23", "@qwer");
  UserInfo user2("asdf", "+7-456-632-81-28", "@asdf");

  binary_file_handler->input_to_file(user1);
  binary_file_handler->input_to_file(user2);

  binary_file_handler->output_from_file();

  delete binary_file_handler;
}

TEST(tests, test_2) {
  BinaryFileHandler *binary_file_handler = new BinaryFileHandler("out.bin");

  UserInfo user1("qwer", "+7-916-254-76-23", "@qwer");
  UserInfo user2("asdf", "+7-456-632-81-28", "@asdf");
  UserInfo user3("zxcv", "+7-646-245-61-84", "@zxcv");

  binary_file_handler->input_to_file(user1);
  binary_file_handler->input_to_file(user2);
  binary_file_handler->input_to_file(user3);

  UserInfo *answ = binary_file_handler->linear_search("+7-646-245-61-84");

  EXPECT_EQ("zxcv", answ->name);
  EXPECT_EQ("+7-646-245-61-84", answ->phone);
  EXPECT_EQ("@zxcv", answ->address);

  delete binary_file_handler;
}