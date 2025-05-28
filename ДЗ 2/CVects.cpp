#include "CVects.h"
#include "CAngls.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

CVects::CVects(int n) : size(n) {
    data = new Vector[n];
    for (int i = 0; i < n; ++i) {
        data[i] = { 0.0, 0.0 };
    }
}

CVects::CVects(const CVects& other) : size(other.size) {
    data = new Vector[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

CVects::CVects(CVects&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

CVects::~CVects() {
    delete[] data;
}

CVects& CVects::operator=(const CVects& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new Vector[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

CVects& CVects::operator=(CVects&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

CVects& CVects::operator++() {
    Vector* newData = new Vector[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = { static_cast<double>(rand() % 100), static_cast<double>(rand() % 100) };
    delete[] data;
    data = newData;
    ++size;
    return *this;
}

CVects CVects::operator++(int) {
    CVects temp(*this);
    ++(*this);
    return temp;
}

CVects& CVects::operator--() {
    if (size > 0) {
        Vector* newData = new Vector[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        --size;
    }
    return *this;
}

CVects CVects::operator--(int) {
    CVects temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const CVects& v) {
    os << "Вектора (" << v.size << "):\n";
    for (int i = 0; i < v.size; ++i) {
        os << "  [" << i << "]: (" << v.data[i].x << ", " << v.data[i].y << ")\n";
    }
    return os;
}

void CVects::readFromFile(std::istream& is) {
    if (!is) {
        std::cerr << "Ошибка ввода строки" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        if (!(is >> data[i].x >> data[i].y)) {
            std::cerr << "Ошибка элемента " << i << std::endl;
            // Заполняем оставшиеся элементы случайными значениями, если файл закончился
            data[i].x = static_cast<double>(rand() % 100);
            data[i].y = static_cast<double>(rand() % 100);
        }
    }
}

/*
void CVects::generateRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        data[i].x = static_cast<double>(rand() % 100);
        data[i].y = static_cast<double>(rand() % 100);
    }
}
*/