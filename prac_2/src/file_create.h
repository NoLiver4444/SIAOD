#ifndef FILE_CREATE_H_
#define FILE_CREATE_H_

#include "main.h"

#define PHONE_NUMBER =

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

  void input_to_file(UserInfo user_data);
  void output_from_file();

  UserInfo *linear_search(string phone);
};

#endif