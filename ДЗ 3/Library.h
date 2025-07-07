#pragma once
#include "Book.h"
#include <unordered_set>
#include <mutex>
#include <string>

class Library {
private:
    std::unordered_set<Book> books;
    mutable std::mutex mtx;

public:
    void addBook(const Book&);
    bool removeBook(const std::string& title);
    Book* findBook(const std::string& title);
    void editBook(const std::string& title);
    void listBooks() const;
    void sortByTitle() const;
    void sortByAuthor() const;
    void sortByGenre() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
