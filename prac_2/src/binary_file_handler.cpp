#include "binary_file_handler.h"

BinaryFileHandler::BinaryFileHandler(string file_name) : file_name(file_name) {}

BinaryFileHandler::~BinaryFileHandler() {
    ofstream binFile(file_name, ios::binary | ios::trunc);
    binFile.close();
}

void BinaryFileHandler::input_to_file(UserInfo user_data) {
  ofstream binFile(file_name, ios::binary | ios::app);

  size_t name_len = user_data.name.size();
  binFile.write(reinterpret_cast<const char *>(&name_len), sizeof(name_len));
  binFile.write(user_data.name.c_str(), name_len);

  size_t phone_len = user_data.phone.size();
  binFile.write(reinterpret_cast<const char *>(&phone_len), sizeof(phone_len));
  binFile.write(user_data.phone.c_str(), phone_len);

  size_t address_len = user_data.address.size();
  binFile.write(reinterpret_cast<const char *>(&address_len),
                sizeof(address_len));
  binFile.write(user_data.address.c_str(), address_len);

  binFile.close();
}

void BinaryFileHandler::binary_to_UserInfo(UserInfo *user, ifstream& binFile) {
    size_t name_len, phone_len, address_len;

    binFile.read(reinterpret_cast<char *>(&name_len), sizeof(name_len));
    user->name.resize(name_len);
    binFile.read(&user->name[0], name_len);

    binFile.read(reinterpret_cast<char *>(&phone_len), sizeof(phone_len));
    user->phone.resize(phone_len);
    binFile.read(&user->phone[0], phone_len);

    binFile.read(reinterpret_cast<char *>(&address_len), sizeof(address_len));
    user->address.resize(address_len);
    binFile.read(&user->address[0], address_len);
}

void BinaryFileHandler::output_from_file() {
  ifstream binFile(file_name, ios::binary);
  UserInfo user;

  cout << "All users in file:" << endl;
  cout << "==================" << endl;

  while (binFile.peek() != EOF) {
    this->binary_to_UserInfo(&user, binFile);

    cout << "Name: " << user.name << endl;
    cout << "Phone: " << user.phone << endl;
    cout << "Address: " << user.address << endl;
    cout << "------------------" << endl;
  }

  binFile.close();
}

void BinaryFileHandler::binary_to_txt() {
    ifstream binFile(file_name, ios::binary);
    ofstream txtFile(file_name + ".txt");
  UserInfo user;

  while (binFile.peek() != EOF) {
    binary_to_UserInfo(&user, binFile);

    txtFile << user.name << ": " << user.phone << ", " << user.address << endl;
  }

  binFile.close();
  txtFile.close();
}

void BinaryFileHandler::random_file(int len) {
    UserInfo *data = new UserInfo();

    for (int i = 0; i < len; ++i) {
        data->name = get_random_name();
        data->phone = get_random_phone();
        data->address = get_random_address();

        this->input_to_file(*data);
    }

    delete data;
}

UserInfo BinaryFileHandler::linear_search(string phone) {
  ifstream binFile(file_name, ios::binary);
  UserInfo user;

  while (binFile.peek() != EOF) {
    binary_to_UserInfo(&user, binFile);

    if (phone == user.phone) {
      return user;
    }
  }

  user.name = "";
  user.phone = "";
  user.address = "";

  return user;
}