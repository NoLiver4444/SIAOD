#ifndef RABIN_KARP_H_
#define RABIN_KARP_H_

#include <iostream>
#include <string>
#include <vector>

class RabinKarpPlagiarismChecker {
 private:
  const int prime_base = 257;
  const int prime_mod = 1000000007;

 public:
  long long hashFunc(const std::string& str, int start, int end);
  std::vector<int> findOccurrences(const std::string& text,
                                   const std::string& pattern);
  bool checkPlagiarism(const std::string& original_text,
                       const std::string& suspected_text,
                       int min_match_length = 10);

  double calculateConfidence(const std::string& original_text,
                             const std::string& suspected_text,
                             int min_match_length = 10);

  double calculatePlagiarismPercentage(const std::string& original_text,
                                       const std::string& suspected_text,
                                       int min_match_length = 10);

  void detailedCheck(const std::string& original_text,
                     const std::string& suspected_text,
                     int min_match_length = 10);
};

std::string safeSubstr(const std::string& str, int start, int length);

#endif