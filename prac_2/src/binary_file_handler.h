#ifndef BINARY_FILE_HANDLER_
#define BINARY_FILE_HANDLER_

#include <cstring>
#include <fstream>

#include "main.h"

// Структура для хранения данных о пользователе
typedef struct {
  string name;
  string phone;
  string address;
} UserInfo;

// Структура для элемента таблицы с индексами
typedef struct IndexEntry {
  string phone;
  streampos offset;

  bool operator<(const IndexEntry& other) const { return phone < other.phone; }

  bool operator==(const string& phone_key) const { return phone == phone_key; }
} IndexTable;

// Класс для работы с бинарными файлами
class BinaryFileHandler {
 private:
  // Имя файла (bin и txt одновременно)
  string file_name;

  // Вектор для создания таблицы с индексами
  vector<IndexTable> index_table;

  // boll переменная для проверки создания таблицы индексов
  bool index_loaded = false;

  void binary_to_UserInfo(UserInfo* user, ifstream& binFile);

 public:
  BinaryFileHandler(string file_name);
  ~BinaryFileHandler();

  void input_to_file(UserInfo user_data);
  void binary_to_txt();
  void output_from_file();
  void random_file(int len);

  UserInfo linear_search(string phone);

  void create_index();
  streampos binary_search_index(const string& phone);
  string binary_search_result(const string& phone);
};

#endif