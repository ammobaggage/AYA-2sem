#include "Library.h"
#include <thread>
#include <Windows.h>
#include <iostream>

void threadSave(Library& lib, const std::string& filename) {
    lib.saveToFile(filename);
}

void threadLoad(Library& lib, const std::string& filename) {
    lib.loadFromFile(filename);
}

void runInteractive(Library& lib, const std::string& filename) {
    int choice;
    while (true) {
        std::cout << "\n1. Добавить книгу\n2. Найти книгу\n3. Удалить книгу\n4. Редактировать\n"
                  << "5. Список\n6. Сортировка по названию\n7. Сортировка по автору\n8. Сортировка по жанру\n"
                  << "9. Сохранить\n0. Выход\n> ";
        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
            case 1: {
                std::string title, author;
                int year, genre;
                std::cout << "Название: ";
                std::getline(std::cin, title);
                std::cout << "Автор: ";
                std::getline(std::cin, author);
                std::cout << "Год: "; std::cin >> year;
                std::cout << "Жанр:\n"
                          << " 0 — Художественная литература\n"
                          << " 1 — Документальная литература\n"
                          << " 2 — Научная литература\n"
                          << " 3 — Биография\n"
                          << "Введите номер жанра: ";
                std::cin >> genre;
                lib.addBook(Book(title, author, year, Book::genreFromInt(genre)));
                break;
            }
            case 2: {
                std::string title;
                std::cout << "Название: ";
                std::getline(std::cin, title);
                Book* b = lib.findBook(title);
                if (b) std::cout << *b << std::endl;
                else std::cout << "Не найдено\n";
                break;
            }
            case 3: {
                std::string title;
                std::cout << "Название: ";
                std::getline(std::cin, title);
                if (lib.removeBook(title)) std::cout << "Удалено\n";
                else std::cout << "Не найдено\n";
                break;
            }
            case 4: {
                std::string title;
                std::cout << "Название редактируемой книги: ";
                std::getline(std::cin, title);
                lib.editBook(title);
                break;
            }
            case 5: lib.listBooks(); break;
            case 6: lib.sortByTitle(); break;
            case 7: lib.sortByAuthor(); break;
            case 8: lib.sortByGenre(); break;
            case 9: {
                std::thread t(threadSave, std::ref(lib), filename); t.join();
                std::cout << "Сохранено в " << filename << "\n";
                break;
            }
            case 0: return;
            default: std::cout << "Неверный ввод\n";
        }
    }
}

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Library lib;
    std::string filename;

    try {
        if (argc > 1 && std::string(argv[1]) == "--load") {
            std::cout << "Введите имя файла для загрузки: ";
            std::getline(std::cin, filename);
            std::thread t(threadLoad, std::ref(lib), filename); t.join();
            lib.listBooks();
        } else if (argc > 1 && std::string(argv[1]) == "--manual") {
            std::cout << "Введите имя файла для сохранения: ";
            std::getline(std::cin, filename);
            runInteractive(lib, filename);
            std::thread t(threadSave, std::ref(lib), filename); t.join();
        } else {
            std::cout << "Введите имя файла для работы (чтение/сохранение): ";
            std::getline(std::cin, filename);
            std::thread t(threadLoad, std::ref(lib), filename); t.join();
            runInteractive(lib, filename);
            std::thread t2(threadSave, std::ref(lib), filename); t2.join();
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
