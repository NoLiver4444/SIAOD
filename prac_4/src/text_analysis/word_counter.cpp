#include "word_counter.h"

StringData::StringData(std::string line) {
  stringParser(line);

  first_word = words[0];
}

void StringData::stringParser(std::string line) {
  std::stringstream ss(line);
  std::string word;

  while (ss >> word) {
    std::string clean_word;

    for (char c : word) {
      if (!std::ispunct(static_cast<unsigned char>(c))) {
        clean_word += std::tolower(static_cast<unsigned char>(c));
      }
    }

    if (!clean_word.empty()) {
      words.push_back(clean_word);
    }
  }
}

int StringData::countWord() {
  int count = 0;

  for (const auto& str : words) {
    if (first_word == str) {
      ++count;
    }
  }

  return count;
}