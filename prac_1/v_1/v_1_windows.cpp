#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>

using namespace std;

// Функция для преобразования и вывода числа в двоичном виде
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Число для преобразования в двоичный вид
    unsigned int x = 25;
    // 32 - число бит в int
    const int n = sizeof(int)*8;
    // maska = 10000000 00000000 00000000 00000000
    unsigned maska = (1 << (n - 1));

    cout << bitset<n> (maska) << endl;

    /*
        1. Проверяем установлен ли бит.
        2. сдвигаем результат для получения 1 или 0.
        3. сдвтгаем маску вправо на один бит.
    */
    for (int i = 1; i <= n; ++i) {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
    system("pause");
    return 0;
}
