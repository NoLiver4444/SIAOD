#include <iostream>
#include <bitset>
#include <chrono>
#include <thread>

using namespace std;

// Кроссплатформенная функция паузы
void system_pause() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Нажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    #endif
}

// Кроссплатформенная функция установки кодировки (только для Windows)
void set_console_encoding() {
    #ifdef _WIN32
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    #endif
}

int main() {
    set_console_encoding();

    // Число для преобразования в двоичный вид
    unsigned int x = 25;
    // Число бит в int
    const int n = sizeof(int) * 8;
    // maska = 10000000 00000000 00000000 00000000
    unsigned maska = (1U << (n - 1));  // Используем U для unsigned

    cout << "Маска: " << bitset<n>(maska) << endl;
    cout << "Число " << x << " в двоичном виде: ";

    /*
        1. Проверяем установлен ли бит.
        2. Сдвигаем результат для получения 1 или 0.
        3. Сдвигаем маску вправо на один бит.
    */
    for (int i = 1; i <= n; ++i) {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    
    cout << endl;
    cout << "Проверка через bitset: " << bitset<n>(x) << endl;
    
    system_pause();
    return 0;
}