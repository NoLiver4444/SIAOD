#ifndef BIT_SORT_H_
#define BIT_SORT_H_

#include "main.h"

unsigned char sort_8_bit_kit(vector<int> original_vector);
void print_8_bit_kit(unsigned char bit_kit, int len);

unsigned long long sort_64_bit_kit(vector<int> original_vector);
void print_64_bit_kit(unsigned long long bit_kit, int len);

vector<unsigned char> sort_64_bit_unsigned_kit(vector<int> original_vector);
void print_64_bit_unsigned_kit(vector<unsigned char> bit_kit);

#endif