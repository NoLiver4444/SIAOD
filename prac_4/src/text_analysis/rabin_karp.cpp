#include "rabin_karp.h"

long long RabinKarpPlagiarismChecker::hashFunc(const std::string& str,
                                               int start, int end) {
  long long hash = 0;

  for (int i = start; i <= end; i++) {
    hash = (hash * prime_base + static_cast<unsigned char>(str[i])) % prime_mod;
  }

  return hash;
}

std::vector<int> RabinKarpPlagiarismChecker::findOccurrences(
    const std::string& text, const std::string& pattern) {
  std::vector<int> occurrences;
  int n = text.length();
  int m = pattern.length();

  if (m == 0 || n < m) return occurrences;

  long long pattern_hash = hashFunc(pattern, 0, m - 1);
  long long text_hash = hashFunc(text, 0, m - 1);

  long long power = 1;
  for (int i = 0; i < m - 1; i++) {
    power = (power * prime_base) % prime_mod;
  }

  if (pattern_hash == text_hash) {
    bool exact_match = true;
    for (int j = 0; j < m; j++) {
      if (text[j] != pattern[j]) {
        exact_match = false;
        break;
      }
    }
    if (exact_match) {
      occurrences.push_back(0);
    }
  }

  for (int i = 1; i <= n - m; i++) {
    text_hash = (text_hash - static_cast<unsigned char>(text[i - 1]) * power) %
                prime_mod;
    if (text_hash < 0) text_hash += prime_mod;
    text_hash =
        (text_hash * prime_base + static_cast<unsigned char>(text[i + m - 1])) %
        prime_mod;

    if (pattern_hash == text_hash) {
      bool exact_match = true;
      for (int j = 0; j < m; j++) {
        if (text[i + j] != pattern[j]) {
          exact_match = false;
          break;
        }
      }
      if (exact_match) {
        occurrences.push_back(i);
      }
    }
  }

  return occurrences;
}

bool RabinKarpPlagiarismChecker::checkPlagiarism(
    const std::string& original_text, const std::string& suspected_text,
    int min_match_length) {
  if (suspected_text.length() < min_match_length) {
    return false;
  }

  std::cout << "Поиск совпадений..." << std::endl;

  // Ищем от самых длинных подстрок к самым коротким
  for (int length = suspected_text.length(); length >= min_match_length;
       length--) {
    for (int start = 0; start <= suspected_text.length() - length; start++) {
      std::string substring = safeSubstr(suspected_text, start, length);

      // Пропускаем слишком короткие подстроки после безопасного извлечения
      if (substring.length() < min_match_length) continue;

      std::vector<int> occurrences = findOccurrences(original_text, substring);
      if (!occurrences.empty()) {
        std::cout << "✓ Найдено совпадение: \"" << substring << "\""
                  << std::endl;
        std::cout << "  Длина: " << substring.length() << " символов"
                  << std::endl;
        std::cout << "  Позиция в подозрительном: " << start << std::endl;
        std::cout << "  Позиция в оригинале: " << occurrences[0] << std::endl;
        return true;
      }
    }
  }

  std::cout << "✗ Совпадений не найдено" << std::endl;
  return false;
}

double RabinKarpPlagiarismChecker::calculateConfidence(
    const std::string& original_text, const std::string& suspected_text,
    int min_match_length) {
  if (suspected_text.length() < min_match_length) {
    return 0.0;
  }

  int total_matches = 0;
  int total_checks = 0;

  for (int length = min_match_length; length <= suspected_text.length();
       length++) {
    for (int start = 0; start <= suspected_text.length() - length; start++) {
      std::string substring = safeSubstr(suspected_text, start, length);
      if (substring.length() < min_match_length) continue;

      total_checks++;

      std::vector<int> occurrences = findOccurrences(original_text, substring);
      if (!occurrences.empty()) {
        total_matches++;
      }
    }
  }

  if (total_checks == 0) return 0.0;

  return static_cast<double>(total_matches) / total_checks;
}

double RabinKarpPlagiarismChecker::calculatePlagiarismPercentage(
    const std::string& original_text, const std::string& suspected_text,
    int min_match_length) {
  if (suspected_text.empty()) {
    return 0.0;
  }

  std::vector<bool> matched(suspected_text.length(), false);
  int total_matched_chars = 0;

  std::cout << "Расчет процента плагиата..." << std::endl;

  // Сначала ищем самые длинные совпадения
  for (int length = suspected_text.length(); length >= min_match_length;
       length--) {
    for (int start = 0; start <= suspected_text.length() - length; start++) {
      // Пропускаем уже совпавшие символы
      bool already_matched = false;
      for (int i = start; i < start + length; i++) {
        if (i < matched.size() && matched[i]) {
          already_matched = true;
          break;
        }
      }
      if (already_matched) continue;

      std::string substring = safeSubstr(suspected_text, start, length);
      if (substring.length() < min_match_length) continue;

      std::vector<int> occurrences = findOccurrences(original_text, substring);

      if (!occurrences.empty()) {
        // Помечаем символы как совпавшие
        for (int i = start; i < start + length; i++) {
          if (i < matched.size()) {
            matched[i] = true;
          }
        }
        total_matched_chars += substring.length();

        std::cout << "  Совпадение: \"" << substring
                  << "\" (длина: " << substring.length() << ")" << std::endl;
      }
    }
  }

  double percentage =
      (static_cast<double>(total_matched_chars) / suspected_text.length()) *
      100.0;
  std::cout << "  Итого: " << total_matched_chars << " из "
            << suspected_text.length() << " символов (" << percentage << "%)"
            << std::endl;

  return percentage;
}

void RabinKarpPlagiarismChecker::detailedCheck(
    const std::string& original_text, const std::string& suspected_text,
    int min_match_length) {
  std::cout << "=== ДЕТАЛЬНАЯ ПРОВЕРКА НА ПЛАГИАТ ===" << std::endl;
  std::cout << "Длина оригинального текста: " << original_text.length()
            << " символов" << std::endl;
  std::cout << "Длина проверяемого текста: " << suspected_text.length()
            << " символов" << std::endl;
  std::cout << "Минимальная длина совпадения: " << min_match_length
            << " символов" << std::endl;
  std::cout << std::endl;

  // Поиск совпадений
  std::cout << "=== ПОИСК СОВПАДЕНИЙ ===" << std::endl;
  bool found_plagiarism =
      checkPlagiarism(original_text, suspected_text, min_match_length);

  std::cout << std::endl;

  // Расчет показателей
  std::cout << "=== РАСЧЕТ ПОКАЗАТЕЛЕЙ ===" << std::endl;
  double percentage = calculatePlagiarismPercentage(
      original_text, suspected_text, min_match_length);
  double confidence =
      calculateConfidence(original_text, suspected_text, min_match_length);

  std::cout << std::endl;
  std::cout << "=== РЕЗУЛЬТАТЫ ===" << std::endl;
  std::cout << "Найдены совпадения: " << (found_plagiarism ? "ДА" : "НЕТ")
            << std::endl;
  std::cout << "Уверенность: " << (confidence * 100) << "%" << std::endl;
  std::cout << "Процент плагиата: " << percentage << "%" << std::endl;

  std::cout << std::endl;
  std::cout << "=== ИНТЕРПРЕТАЦИЯ ===" << std::endl;
  if (percentage < 5) {
    std::cout << "✓ Незначительные совпадения" << std::endl;
  } else if (percentage < 20) {
    std::cout << "⚠ Возможные заимствования" << std::endl;
  } else if (percentage < 40) {
    std::cout << "⚠ Вероятный плагиат" << std::endl;
  } else if (percentage < 60) {
    std::cout << "✗ Плагиат" << std::endl;
  } else {
    std::cout << "✗ Очевидный плагиат" << std::endl;
  }
}

std::string safeSubstr(const std::string& str, int start, int length) {
  if (start < 0 || start >= str.length() || length <= 0) return "";

  // Для простоты, просто обрезаем если выходим за границы
  if (start + length > str.length()) {
    length = str.length() - start;
  }

  return str.substr(start, length);
}