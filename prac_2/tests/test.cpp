#include "test.h"

TEST(number_1_2, test_1) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out.bin");

  UserInfo user1("qwer", "+7-916-254-76-23", "@qwer");
  UserInfo user2("asdf", "+7-456-632-81-28", "@asdf");

  binary_file_handler->input_to_file(user1);
  binary_file_handler->input_to_file(user2);

  binary_file_handler->output_from_file();

  delete binary_file_handler;
}

TEST(number_1_2, test_2) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out.bin");

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

TEST(number_1_2, test_3) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_1.bin");

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

TEST(number_1_2, test_4) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_2.bin");

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

TEST(number_1_2, test_5) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_3.bin");

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

TEST(number_1_2, test_6) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_3.bin");

  binary_file_handler->random_file(100);

  UserInfo answ = binary_file_handler->linear_search("+9-999-999-99-99");

  EXPECT_EQ("", answ.name);
  EXPECT_EQ("", answ.phone);
  EXPECT_EQ("", answ.address);

  binary_file_handler->binary_to_txt();

  delete binary_file_handler;
}

TEST(number_3, test_1) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_4.bin");

  binary_file_handler->random_file(5000);

  UserInfo user3("zxcv", "+9-999-999-99-99", "@zxcv");
  binary_file_handler->input_to_file(user3);

  binary_file_handler->random_file(4999);

  binary_file_handler->create_index();
  string answ = binary_file_handler->binary_search_result("+9-999-999-99-99");

  binary_file_handler->binary_to_txt();

  EXPECT_EQ("zxcv: +9-999-999-99-99, @zxcv\n", answ);

  delete binary_file_handler;
}

TEST(number_3, test_2) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_4.bin");

  binary_file_handler->random_file(5000);

  UserInfo user3("zxcv", "+1-111-111-11-11", "@zxcv");
  binary_file_handler->input_to_file(user3);

  binary_file_handler->random_file(4999);

  binary_file_handler->create_index();
  string answ = binary_file_handler->binary_search_result("+1-111-111-11-11");

  binary_file_handler->binary_to_txt();

  EXPECT_EQ("zxcv: +1-111-111-11-11, @zxcv\n", answ);

  delete binary_file_handler;
}

TEST(number_3, test_3) {
  BinaryFileHandler *binary_file_handler =
      new BinaryFileHandler("answ/out_4.bin");

  binary_file_handler->random_file(100);

  binary_file_handler->create_index();
  string answ = binary_file_handler->binary_search_result("+9-999-999-99-99");

  binary_file_handler->binary_to_txt();

  EXPECT_EQ("not found", answ);

  delete binary_file_handler;
}