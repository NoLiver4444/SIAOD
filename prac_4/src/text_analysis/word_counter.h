#ifndef WORD_COUNTER_H_
#define WORD_COUNTER_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class StringData {
 private:
  std::vector<std::string> words;
  std::string first_word;

  void stringParser(std::string line);

 public:
  StringData(std::string line);

  int countWord();
};

#endif