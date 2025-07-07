#pragma once
#include <string>
#include <iostream>

enum class BookGenre { Fiction = 0, NonFiction, Science, Biography, Unknown };

class Book {
private:
    std::string title;
    std::string author;
    int year;
    BookGenre genre;

public:
    Book();
    Book(const std::string&, const std::string&, int, BookGenre);

    bool operator==(const Book& other) const;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    BookGenre getGenre() const;

    void setTitle(const std::string&);
    void setAuthor(const std::string&);
    void setYear(int);
    void setGenre(BookGenre);

    std::string genreToString() const;
    static BookGenre genreFromInt(int g);

    friend std::ostream& operator<<(std::ostream&, const Book&);
};

namespace std {
    template<>
    struct hash<Book> {
        size_t operator()(const Book& b) const {
            return hash<string>()(b.getTitle() + b.getAuthor());
        }
    };
}
