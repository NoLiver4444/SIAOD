#include "file_bit_sort.h"

void file_bit_sort(ifstream &input_file, string out_file_name) {
  vector<bool> bit_vector(9000000, false);
  int file_value = 0;

  auto start = high_resolution_clock::now();
  // Чтение из входного файла
  while (input_file >> file_value) {
    bit_vector[file_value - 1000000] = true;
  }

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  cout << "Time: " << duration.count() << " ms" << endl;

  size_t memory_used = sizeof(bit_vector);
  size_t storage_memory = (9000000 + 7) / 8;
  cout << "bit: " << (memory_used + storage_memory) * 8
       << "    byte: " << memory_used + storage_memory
       << "    MB: " << (memory_used + storage_memory) / (1024 * 1024) << endl;

  print_bit_mas(bit_vector, out_file_name);
}

void print_bit_mas(vector<bool> bit_vector, string out_file_name) {
  ofstream output_file(out_file_name);

  for (size_t i = 0; i < bit_vector.size(); ++i) {
    if (bit_vector[i]) {
      output_file << i + 1000000 << endl;
    }
  }

  output_file.close();
}