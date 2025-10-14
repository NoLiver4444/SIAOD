#include "main.h"

int main() {
  RabinKarpPlagiarismChecker checker;

  std::string original_text;
  std::string suspected_text;
  std::string skip;
  std::string word_counter;
  int min_len = 0;

  int choose;

  while (1) {
    std::cout << "1. word counter\n2. Rabin Karp\n0. exit\n";
    std::cin >> choose;
    std::getline(std::cin, skip);

    if (choose == 1) {
      while (1) {
        std::cout << "Введите текст:\n";
        std::getline(std::cin, word_counter);

        if (word_counter == "") {
          break;
        }

        StringData data(word_counter);

        std::cout << data.countWord() << std::endl;
      }
    } else if (choose == 2) {
      while (1) {
        std::cout << "Введите оригинальный текст:\n";
        std::getline(std::cin, original_text);

        std::cout << "\nВведите проверяемый текст:\n";
        std::getline(std::cin, suspected_text);

        std::cout << "\nВведите минимальную длину текста:\n";
        std::cin >> min_len;

        std::getline(std::cin, skip);

        if (original_text == "" && suspected_text == "" && min_len == 0) {
          break;
        }

        checker.detailedCheck(original_text, suspected_text, min_len);
      }
    } else if (choose == 0) {
      break;
    }
  }

  return 0;
}