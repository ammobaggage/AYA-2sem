#include "Library.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

void Library::addBook(const Book& b) {
    std::lock_guard<std::mutex> lock(mtx);
    books.insert(b);
}

bool Library::removeBook(const std::string& title) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            return true;
        }
    }
    return false;
}

Book* Library::findBook(const std::string& title) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& b : books) {
        if (b.getTitle() == title)
            return const_cast<Book*>(&b);
    }
    return nullptr;
}

void Library::editBook(const std::string& title) {
    Book* book = findBook(title);
    if (!book) {
        std::cout << "Книга не найдена!\n";
        return;
    }

    std::string newTitle, newAuthor;
    int newYear, genre;
    std::cin.ignore();
    std::cout << "Новое название: ";
    std::getline(std::cin, newTitle);
    std::cout << "Новый автор: ";
    std::getline(std::cin, newAuthor);
    std::cout << "Новый год: ";
    std::cin >> newYear;
    std::cout << "Новый жанр:\n"
              << " 0 — Художественная литература\n"
              << " 1 — Документальная литература\n"
              << " 2 — Научная литература\n"
              << " 3 — Биография\n"
              << "Введите номер жанра: ";
    std::cin >> genre;

    book->setTitle(newTitle);
    book->setAuthor(newAuthor);
    book->setYear(newYear);
    book->setGenre(Book::genreFromInt(genre));
}

void Library::listBooks() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "\nНазвание           | Автор             | Год  | Жанр\n"
              << "-------------------|--------------------|------|----------\n";
    for (const auto& b : books)
        std::cout << b << std::endl;
}

void Library::sortByTitle() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<Book> sorted(books.begin(), books.end());
    std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });

    std::cout << "\nНазвание           | Автор             | Год  | Жанр\n"
              << "-------------------|--------------------|------|----------\n";
    for (const auto& b : sorted)
        std::cout << b << std::endl;
}

void Library::sortByAuthor() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<Book> sorted(books.begin(), books.end());
    std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
    });

    std::cout << "\nНазвание           | Автор             | Год  | Жанр\n"
              << "-------------------|--------------------|------|----------\n";
    for (const auto& b : sorted)
        std::cout << b << std::endl;
}

void Library::sortByGenre() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<Book> sorted(books.begin(), books.end());
    std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) {
        return a.getGenre() < b.getGenre();
    });

    std::cout << "\nНазвание           | Автор             | Год  | Жанр\n"
              << "-------------------|--------------------|------|----------\n";
    for (const auto& b : sorted)
        std::cout << b << std::endl;
}

void Library::saveToFile(const std::string& filename) const {
    std::lock_guard<std::mutex> lock(mtx);
    std::ofstream out(filename);
    for (const auto& b : books)
        out << b.getTitle() << ";" << b.getAuthor() << ";" << b.getYear() << ";" << static_cast<int>(b.getGenre()) << "\n";
}

void Library::loadFromFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(mtx);
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Файл не найден!");

    std::string title, author;
    int year, genre;
    while (std::getline(in, title, ';') &&
           std::getline(in, author, ';') &&
           (in >> year).ignore() &&
           (in >> genre).ignore()) {
        books.emplace(title, author, year, Book::genreFromInt(genre));
    }
}
