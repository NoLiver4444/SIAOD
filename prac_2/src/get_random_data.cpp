#include "get_random_data.h"

string get_random_number() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, 9);

  return to_string(dis(gen));
}

string get_random_phone() {
  string phone = "+7-";

  for (int i = 0; i < 3; ++i) {
    phone += get_random_number();
  }
  phone += "-";
  for (int i = 0; i < 3; ++i) {
    phone += get_random_number();
  }
  phone += "-";
  for (int i = 0; i < 2; ++i) {
    phone += get_random_number();
  }
  phone += "-";
  for (int i = 0; i < 2; ++i) {
    phone += get_random_number();
  }

  return phone;
}

string get_random_name() {
  vector<string> first_names = {
      "Иван",   "Петр",    "Алексей", "Дмитрий",   "Сергей",   "Андрей",
      "Михаил", "Максим",  "Артем",   "Александр", "Егор",     "Никита",
      "Анна",   "Мария",   "Елена",   "Ольга",     "Наталья",  "Екатерина",
      "Ирина",  "Татьяна", "Юлия",    "Светлана",  "Виктория", "Анастасия"};

  vector<string> last_names = {
      "Иванов",   "Петров",  "Сидоров", "Смирнов", "Кузнецов", "Попов",
      "Васильев", "Новиков", "Федоров", "Морозов", "Волков",   "Алексеев",
      "Лебедев",  "Семенов", "Егоров",  "Павлов",  "Козлов",   "Степанов",
      "Николаев", "Орлов",   "Андреев", "Макаров", "Никитин",  "Захаров"};

  static random_device rd;
  static mt19937 gen(rd());
  static uniform_int_distribution<size_t> first_dis(0, first_names.size() - 1);
  static uniform_int_distribution<size_t> last_dis(0, last_names.size() - 1);

  return first_names[first_dis(gen)] + " " + last_names[last_dis(gen)];
}

string get_random_address() {
  static vector<string> street_types = {"ул.", "пр.", "бульвар", "пер."};
  static vector<string> street_names = {
      "Ленина",    "Мира",   "Центральная", "Садовая", "Победы", "Молодежная",
      "Советская", "Кирова", "Гагарина",    "Лесная",  "Речная", "Школьная"};

  static random_device rd;
  static mt19937 gen(rd());
  static uniform_int_distribution<int> street_type_dis(0,
                                                       street_types.size() - 1);
  static uniform_int_distribution<int> street_name_dis(0,
                                                       street_names.size() - 1);
  static uniform_int_distribution<int> house_dis(1, 200);
  static uniform_int_distribution<int> apt_dis(1, 300);

  return street_types[street_type_dis(gen)] + " " +
         street_names[street_name_dis(gen)] + ", " + "д. " +
         to_string(house_dis(gen)) + ", " + "кв. " + to_string(apt_dis(gen));
}