#include "main.h"

int main() {
  int choose;
  HashTable hash_table;

  string title, author;
  int isbn;

  while (true) {
    cout << "choose:\n1. insert\n2. search\n3. remove\n4. auto fill\n5. "
            "display\n6. exit\n\n";
    cin >> choose;

    if (choose == 1) {
      cout << "\ntitle: ";
      cin >> title;

      cout << "\nauthor: ";
      cin >> author;

      cout << "\nisbn: ";
      cin >> isbn;

      if (hash_table.insert(Book(title, author, isbn))) {
        cout << "Добавлена: " << title << " (ISBN: " << isbn << ")\n";
      } else {
        cout << "Error\n";
      }
    } else if (choose == 2) {
      cout << "\nisbn: ";
      cin >> isbn;

      Book *book = hash_table.search(isbn);

      if (book != nullptr) {
        cout << "ISBN:" << isbn << " \"" << title << "\" " << author << endl;
      } else {
        cout << "Пусто" << endl;
      }
    } else if (choose == 3) {
      cout << "\nisbn: ";
      cin >> isbn;

      if (hash_table.remove(isbn)) {
        cout << "Книга удалена\n";
      } else {
        cout << "Not found\n";
      }
    } else if (choose == 4) {
      hash_table.autoFill();
    } else if (choose == 5) {
      hash_table.display();
    } else if (choose == 6) {
      break;
    }
    cout << endl;
  }

  return 0;
}