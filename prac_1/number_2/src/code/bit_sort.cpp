#include "bit_sort.h"

// 2.а
unsigned char sort_8_bit_kit(vector<int> original_vector) {
  // Создаём набор битов
  unsigned char bit_kit = 0;

  // Проходимся по вектору и с помощью значений ставим биты на нужные индексы
  /*
    1. Берём 1 = 00000001 - 8-разрядную маску.
    2. Устанавливаем (8 - 1 - i) бит в число.
    3. Делаем битовое сложение.
  */
  for (auto i : original_vector) {
    bit_kit |= (1 << (7 - i));
  }

  return bit_kit;
}

// 2.б
unsigned char sort_64_bit_kit(vector<int> original_vector) {
  // Создаём набор битов
  unsigned long long bit_kit = 0;

  // Проходимся по вектору и с помощью значений ствами биты на нужные индексы
  /*
    1. Берём 1 = 00000001 - 8-разрядную маску.
    2. Устанавливаем (64 - 1 - i) бит в число.
    3. Делаем битовое сложение.
  */
  for (auto i : original_vector) {
    bit_kit |= (1 << (63 - i));
  }

  return bit_kit;
}

void print_bit_kit(unsigned char bit_kit, int len) {
  unsigned char maska = (1 << (len - 1));

  for (int i = 0; i < len; ++i) {
    cout << ((bit_kit & maska) ? i : 0) << " ";
    maska = maska >> 1;
  }
  cout << endl;
}