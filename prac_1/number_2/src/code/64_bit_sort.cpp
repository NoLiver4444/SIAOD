#include "bit_sort.h"

// 2.б
unsigned long long sort_64_bit_kit(vector<int> original_vector) {
  unsigned long long bit_kit = 0;

  for (auto i : original_vector) {
    bit_kit |= (1ULL << (63 - i));
  }

  return bit_kit;
}

void print_64_bit_kit(unsigned long long bit_kit, int len) {
  unsigned long long maska = 1ULL << (len - 1);

  for (int i = 0; i < len; ++i) {
    if (bit_kit & maska) {
      cout << i << " ";
    }
    maska >>= 1;
  }
  cout << endl;
}