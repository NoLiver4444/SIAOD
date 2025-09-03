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

// 2.в
vector<unsigned char> sort_64_bit_unsigned_kit(vector<int> original_vector) {
  vector<unsigned char> bit_kit(8, 0);

  for (auto i : original_vector) {
    bit_kit[i / 8] |= (1 << (7 - (i % 8)));
  }

  return bit_kit;
}

void print_64_bit_unsigned_kit(vector<unsigned char> bit_kit) {
  for (int i = 0; i < 8; ++i) {
    unsigned char mask = 0x80;  // 10000000 в двоичной
    for (int j = 0; j < 8; ++j) {
      if (bit_kit[i] & mask) {
        cout << (i * 8 + j) << " ";
      }
      mask >>= 1;
    }
  }
  cout << endl;
}