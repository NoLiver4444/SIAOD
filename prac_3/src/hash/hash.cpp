#include "hash.h"

HashTable::HashTable(int capacity) : size(0), capacity(capacity) {
  table.resize(capacity, nullptr);
}

HashTable::~HashTable() {
  for (int i = 0; i < capacity; ++i) {
    Node *current = table[i];

    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
}

int HashTable::hashFunction(int key) { return key % capacity; }

void HashTable::reHash() {
  int old_capacity = capacity;
  capacity *= 2;

  std::vector<Node *> new_table(capacity, nullptr);

  for (int i = 0; i < old_capacity; ++i) {
    Node *current = table[i];

    while (current != nullptr) {
      Node *next = current->next;

      int new_index = hashFunction(current->data.isbn);

      current->next = new_table[new_index];
      new_table[new_index] = current;

      current = next;
    }
  }

  table = new_table;
}

bool HashTable::insert(const Book &book) {
  bool answ = true;

  if (search(book.isbn) != nullptr) {
    answ = false;
  } else {
    int index = hashFunction(book.isbn);

    Node *new_node = new Node(book);

    new_node->next = table[index];
    table[index] = new_node;

    ++size;

    double loadFactor = (double)size / capacity;

    if (loadFactor > LOAD_FACTOR_THRESHOLD) {
        reHash();
    }
  }

  return answ;
}

Book *HashTable::search(int isbn) {
  int index = hashFunction(isbn);

  Node *current = table[index];

  while (current != nullptr) {
    if (current->data.isbn == isbn) {
      return &(current->data);
    }

    current = current->next;
  }

  return nullptr;
}

bool HashTable::remove(int isbn) {
  int index = hashFunction(isbn);
  bool answ = false;

  Node *current = table[index];

  if (current == nullptr) {
    answ = false;
  } else if (current->data.isbn == isbn) {
    table[index] = current->next;

    delete current;
    --size;

    answ = true;
  } else {
    while (current != nullptr) {
        if (current->next->data.isbn == isbn) {
        Node *nodeToDelete = current->next;

        current->next = nodeToDelete->next;

        delete nodeToDelete;
        size--;

        answ = true;
        }
        current = current->next;
    }
    }

  return answ;
}

void HashTable::autoFill() {
  Book predefinedBooks[] = {
      Book("Война и мир", "Лев Толстой", 101),
      Book("Преступление и наказание", "Федор Достоевский", 203),
      Book("Мастер и Маргарита", "Михаил Булгаков", 307),
      Book("Евгений Онегин", "Александр Пушкин", 412),
      Book("Отцы и дети", "Иван Тургенев", 523),
      Book("Тихий Дон", "Михаил Шолохов", 636),
      Book("Герой нашего времени", "Михаил Лермонтов", 749)};

  int bookCount = sizeof(predefinedBooks) / sizeof(predefinedBooks[0]);

  for (int i = 0; i < bookCount; ++i) {
    if (insert(predefinedBooks[i])) {
      std::cout << "Добавлена: " << predefinedBooks[i].title
                << " (ISBN: " << predefinedBooks[i].isbn << ")" << std::endl;
    }
  }

  std::cout << std::endl;
}

void HashTable::display() {
  std::cout << "\n=== ХЕШ-ТАБЛИЦА ===" << std::endl;
  std::cout << "Размер таблицы: " << capacity << std::endl;
  std::cout << "Количество элементов: " << size << std::endl;
  std::cout << "Коэффициент загрузки: " << (double)size / capacity << std::endl;
  std::cout << "=========================" << std::endl;

  for (int i = 0; i < capacity; ++i) {
    std::cout << "[" << i << "]: ";
    Node *current = table[i];

    if (current == nullptr) {
      std::cout << "пусто";
    } else {
      while (current != nullptr) {
        std::cout << "ISBN:" << current->data.isbn << " \""
                  << current->data.title << "\"";
        if (current->next != nullptr) {
          std::cout << " → ";
        }
        current = current->next;
      }
    }
    std::cout << std::endl;
  }
}

int HashTable::getSize() {
    return size;
}