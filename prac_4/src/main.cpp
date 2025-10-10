#include "main.h"

int main() {
  std::string input;
  std::cout << "Введите строку: ";
  std::getline(std::cin, input);

  StringData data(input);

  cout << "\n\n" << data.countWord() << "\n";
  return 0;
}