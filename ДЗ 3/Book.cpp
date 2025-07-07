#include "Book.h"

Book::Book() : title(""), author(""), year(0), genre(BookGenre::Unknown) {}

Book::Book(const std::string& t, const std::string& a, int y, BookGenre g)
    : title(t), author(a), year(y), genre(g) {}

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author;
}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
BookGenre Book::getGenre() const { return genre; }

void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setYear(int y) { year = y; }
void Book::setGenre(BookGenre g) { genre = g; }

std::string Book::genreToString() const {
    switch (genre) {
        case BookGenre::Fiction: return "Худ. лит.";
        case BookGenre::NonFiction: return "Док. лит.";
        case BookGenre::Science: return "Наука";
        case BookGenre::Biography: return "Биография";
        default: return "Неизв.";
    }
}

BookGenre Book::genreFromInt(int g) {
    switch (g) {
        case 0: return BookGenre::Fiction;
        case 1: return BookGenre::NonFiction;
        case 2: return BookGenre::Science;
        case 3: return BookGenre::Biography;
        default: return BookGenre::Unknown;
    }
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os.width(18); os << std::left << b.title << "| ";
    os.width(18); os << std::left << b.author << "| ";
    os.width(5);  os << std::left << b.year << "| ";
    os << b.genreToString();
    return os;
}
