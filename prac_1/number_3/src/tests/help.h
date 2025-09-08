#ifndef HELP_H
#define HELP_H

#include <algorithm>
#include <chrono>
#include <random>

#include "../code/main.h"

void create_random_values_file(int min_value, int max_value,
                               ofstream &create_file, ofstream &answ_file);
bool check_files(ifstream &file_1, ifstream &file_2);

#endif