#include "bit_oper.h"

/*
--------------------------------------------------
Входные данные:
    х - исходное число.
    maska - маска.
    move - сдвиг битов в маске.
--------------------------------------------------
Порядок выполнения:
    1. Сдвигаем все биты в маске на показатель move.
    2. Побитовая инверсия маски после сдвига.
    3. Выполнение конъюнкции (x & maska).
*/
int bit_mask(unsigned char x, unsigned char maska, int move) {
  unsigned char answ = x & (~(maska << move));
  unsigned char mask_print = 0x80;
  
  for (int i = 0; i < 8; ++i) {
      std::cout << ((answ & mask_print) ? '1' : '0');
      mask_print >>= 1;
  }
  std::cout << std::endl;

  return answ;
}