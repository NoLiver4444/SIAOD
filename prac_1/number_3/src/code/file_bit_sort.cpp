#include "file_bit_sort.h"

void file_bit_sort(ifstream *input_file) {
    vector<bool> bit_vector(10000000, false);
    int file_value;

    while (*input_file >> file_value) {
        bit_vector[file_value] = true;
    }

    print_bit_mas(bit_vector);
}

void print_bit_mas(vector<bool> bit_vector) {
    ofstream output_file("test_1_code_answer.txt");

    for (size_t i = 0; i < bit_vector.size(); ++i) {
        if (bit_vector[i]) {
            output_file << i << endl;
        }
    }
}