#include "main.h"

void runEdgeCaseTests() {
  RabinKarpPlagiarismChecker checker;

  std::cout << "=== ГРАНИЧНЫЕ СЛУЧАИ ===" << std::endl;

  // Тест 7: Очень короткие тексты
  std::string original7 = "Привет мир";
  std::string suspected7 = "Привет";

  std::cout << "\n=== ТЕСТ 7: Короткие тексты ===" << std::endl;
  std::cout << "Оригинал: " << original7 << std::endl;
  std::cout << "Подозрительный: " << suspected7 << std::endl << std::endl;
  checker.detailedCheck(original7, suspected7, 3);

  // Тест 8: Текст меньше минимальной длины
  std::string original8 = "Длинный оригинальный текст";
  std::string suspected8 = "Короткий";

  std::cout << "\n=== ТЕСТ 8: Текст короче минимальной длины ===" << std::endl;
  std::cout << "Оригинал: " << original8 << std::endl;
  std::cout << "Подозрительный: " << suspected8 << std::endl << std::endl;
  checker.detailedCheck(original8, suspected8, 10);

  // Тест 9: Пустые строки
  std::string original9 = "Обычный текст";
  std::string suspected9 = "";

  std::cout << "\n=== ТЕСТ 9: Пустая строка ===" << std::endl;
  std::cout << "Оригинал: " << original9 << std::endl;
  std::cout << "Подозрительный: [ПУСТО]" << std::endl << std::endl;
  checker.detailedCheck(original9, suspected9, 5);
}

int main() {
  // Основные тесты
  RabinKarpPlagiarismChecker checker;

  // Тест 1: Очевидный плагиат
  std::string original1 =
      "Этот текст содержит уникальные идеи и оригинальные формулировки для "
      "проверки системы";
  std::string suspected1 = "Этот текст содержит уникальные идеи";

  std::cout << "=== ТЕСТ 1: Очевидный плагиат ===" << std::endl;
  checker.detailedCheck(original1, suspected1, 5);

  std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

  // Тест 2: Частичный плагиат
  std::string original2 =
      "В современном мире искусственный интеллект играет важную роль в "
      "развитии технологий";
  std::string suspected2 =
      "Многие считают что искусственный интеллект играет важную роль в IT";

  std::cout << "=== ТЕСТ 2: Частичный плагиат ===" << std::endl;
  checker.detailedCheck(original2, suspected2, 5);

  std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

  // Запуск граничных случаев
  runEdgeCaseTests();

  return 0;
}