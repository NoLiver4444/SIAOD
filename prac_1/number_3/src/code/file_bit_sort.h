#ifndef FILE_BIT_SORT_H_
#define FILE_BIT_SORT_H_

#include <chrono>

#include "main.h"

using namespace std::chrono;

void file_bit_sort(ifstream &input_file, string out_file_name);
void print_bit_mas(vector<bool> bit_vector, string out_file_name);

#endif