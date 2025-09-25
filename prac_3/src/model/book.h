#ifndef BOOK_H_
#define BOOK_H_

#include <string>

struct Book {
    std::string title;
    std::string author;
    int isbn;

    Book(std::string title, std::string author, int isbn);
};

#endif