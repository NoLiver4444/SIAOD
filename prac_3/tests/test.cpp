#include "test.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

TEST(hash_table, auto_fill) {
  HashTable hash_table;

  hash_table.autoFill();

  hash_table.display();

  Book *find_book = hash_table.search(523);

  EXPECT_EQ(find_book->title, "Отцы и дети");
}

TEST(hash_table, insert) {
  HashTable hash_table;

  hash_table.insert(Book("qwer", "qewr", 101));
  hash_table.insert(Book("asdf", "asdf", 402));
  hash_table.insert(Book("zxcv", "zxcv", 543));
  hash_table.insert(Book("ghjk", "ghjk", 645));
  hash_table.insert(Book("tyui", "tyui", 762));
  hash_table.insert(Book("dfgh", "dfgh", 101));

  hash_table.display();

  Book *find_book = hash_table.search(101);

  EXPECT_EQ(find_book->title, "qwer");
  EXPECT_EQ(hash_table.getSize(), 5);
}

TEST(hash_table, rehash) {
  HashTable hash_table;

  hash_table.insert(Book("q", "q", 101));
  hash_table.insert(Book("a", "a", 402));
  hash_table.insert(Book("z", "z", 543));
  hash_table.insert(Book("w", "w", 645));
  hash_table.insert(Book("e", "e", 762));
  hash_table.insert(Book("r", "r", 534));
  hash_table.insert(Book("t", "t", 765));
  hash_table.insert(Book("y", "y", 582));
  hash_table.insert(Book("u", "u", 295));
  hash_table.insert(Book("i", "i", 701));
  hash_table.insert(Book("o", "o", 192));
  hash_table.insert(Book("p", "p", 458));
  hash_table.insert(Book("s", "s", 107));
  hash_table.insert(Book("d", "d", 673));
  hash_table.insert(Book("f", "f", 183));
  hash_table.insert(Book("g", "g", 588));

  hash_table.display();

  EXPECT_EQ(hash_table.getSize(), 16);
}

TEST(hash_table, remove) {
  HashTable hash_table;

  hash_table.insert(Book("q", "q", 101));
  hash_table.insert(Book("a", "a", 402));
  hash_table.insert(Book("z", "z", 543));
  hash_table.insert(Book("w", "w", 645));
  hash_table.insert(Book("e", "e", 762));
  hash_table.insert(Book("r", "r", 534));
  hash_table.insert(Book("t", "t", 765));
  hash_table.insert(Book("y", "y", 582));
  hash_table.insert(Book("u", "u", 295));
  hash_table.insert(Book("i", "i", 701));
  hash_table.insert(Book("o", "o", 192));
  hash_table.insert(Book("p", "p", 458));
  hash_table.insert(Book("s", "s", 107));
  hash_table.insert(Book("d", "d", 673));
  hash_table.insert(Book("f", "f", 183));
  hash_table.insert(Book("g", "g", 588));

  hash_table.remove(762);
  hash_table.remove(588);
  hash_table.remove(295);
  hash_table.remove(701);

  hash_table.display();

  EXPECT_EQ(hash_table.search(762), nullptr);
  EXPECT_EQ(hash_table.search(588), nullptr);
  EXPECT_EQ(hash_table.search(295), nullptr);

  EXPECT_EQ(hash_table.remove(100), false);
}