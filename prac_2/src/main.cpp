#include "main.h"

int main() {
  string name, phone, address, answ;
  int choose, len;

  string file_name;

  cout << "File: ";
  cin >> file_name;

  file_name = "answ/" + file_name + ".bin";

  BinaryFileHandler *binary_file_handler = new BinaryFileHandler(file_name);

  UserInfo user;

  while (1) {
    cout << "\n1. Insert data\n2. Random data\n3. Liner search\n4. Binary "
            "search\n5. Print file\n0. Exit\n";
    cin >> choose;

    if (choose == 1) {
      cout << "Name: ";
      cin >> name;
      cout << "\nPhone: ";
      cin >> phone;
      cout << "\nAddress: ";
      cin >> address;

      user.name = name;
      user.phone = phone;
      user.address = address;

      binary_file_handler->input_to_file(user);
    } else if (choose == 2) {
      cout << "\nLen: ";
      cin >> len;

      binary_file_handler->random_file(len);
    } else if (choose == 3) {
      cout << "\nPhone: ";
      cin >> phone;

      auto start = high_resolution_clock::now();
      user = binary_file_handler->linear_search(phone);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      cout << "Search time: " << duration.count() << " microseconds" << endl;

      cout << user.name << ": " << user.phone << ", " << user.address << "\n";
    } else if (choose == 4) {
      cout << "\nPhone: ";
      cin >> phone;

      binary_file_handler->create_index();

      auto start = high_resolution_clock::now();
      answ = binary_file_handler->binary_search_result(phone);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      cout << "Search time: " << duration.count() << " microseconds" << endl;

      cout << "\nAnsw: " << answ << "\n";
    } else if (choose == 5) {
      binary_file_handler->output_from_file();
    } else if (choose == 0) {
      break;
    }

    binary_file_handler->binary_to_txt();
  }

  delete binary_file_handler;

  return 0;
}