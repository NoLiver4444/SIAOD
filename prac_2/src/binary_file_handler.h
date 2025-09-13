#ifndef BINARY_FILE_HANDLER_
#define BINARY_FILE_HANDLER_

#include <cstring>
#include <fstream>

#include "main.h"

typedef struct {
  string name;
  string phone;
  string address;
} UserInfo;

class BinaryFileHandler {
 private:
  string file_name;

 public:
  BinaryFileHandler(string file_name);
  ~BinaryFileHandler();

  void input_to_file(UserInfo user_data);
  void binary_to_UserInfo();
  void output_from_file();
  void binary_to_UserInfo(UserInfo *user, ifstream& binFile);
  void binary_to_txt();
  void random_file(int len);

  UserInfo linear_search(string phone);
};

#endif