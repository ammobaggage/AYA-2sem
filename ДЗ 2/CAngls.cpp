#include "CAngls.h"
#include "CVects.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

CAngls::CAngls(int n) : size(n) {
    data = new double[n];
    for (int i = 0; i < n; ++i) {
        data[i] = 0.0;
    }
}

CAngls::CAngls(const CAngls& other) : size(other.size) {
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

CAngls::CAngls(CAngls&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

CAngls::~CAngls() {
    delete[] data;
}

CAngls& CAngls::operator=(const CAngls& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new double[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

CAngls& CAngls::operator=(CAngls&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

CAngls& CAngls::operator++() {
    double* newData = new double[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = static_cast<double>(rand() % 360);
    delete[] data;
    data = newData;
    ++size;
    return *this;
}

CAngls CAngls::operator++(int) {
    CAngls temp(*this);
    ++(*this);
    return temp;
}

CAngls& CAngls::operator--() {
    if (size > 0) {
        double* newData = new double[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        --size;
    }
    return *this;
}

CAngls CAngls::operator--(int) {
    CAngls temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const CAngls& a) {
    os << "Углы (" << a.size << "):\n";
    for (int i = 0; i < a.size; ++i) {
        os << "  [" << i << "]: " << a.data[i] << " градусов\n";
    }
    return os;
}



// Реализация операторов сложения и вычитания
CVects operator+(const CVects& v, const CAngls& a) {
    int minSize = std::min(v.getSize(), a.getSize());
    CVects result(minSize);

    const CVects::Vector* vData = v.getData();
    const double* aData = a.getData();

    for (int i = 0; i < minSize; ++i) {
        double angle = aData[i] * 3.14 / 180.0; // Переводим в радианы
        double cosA = cos(angle);
        double sinA = sin(angle);

        // Поворачиваем вектор против часовой стрелки
        result.data[i].x = vData[i].x * cosA - vData[i].y * sinA;
        result.data[i].y = vData[i].x * sinA + vData[i].y * cosA;
    }

    return result;
}

CVects operator+(const CAngls& a, const CVects& v) {
    return v + a;
}


CAngls operator-(const CVects& v1, const CVects& v2) {
    int minSize = std::min(v1.getSize(), v2.getSize());
    CAngls result(minSize);

    const CVects::Vector* v1Data = v1.getData();
    const CVects::Vector* v2Data = v2.getData();

    for (int i = 0; i < minSize; ++i) {
        double dot = v1Data[i].x * v2Data[i].x + v1Data[i].y * v2Data[i].y;
        double det = v1Data[i].x * v2Data[i].y - v1Data[i].y * v2Data[i].x;
        result.data[i] = atan2(det, dot) * 180.0 / 3.14;
    }

    return result;
}

void CAngls::readFromFile(std::istream& is) {
    if (!is) {
        std::cerr << "Ошибка ввода" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        if (!(is >> data[i])) {
            std::cerr << "Ошибка чтения элемента " << i << std::endl;
            data[i] = static_cast<double>(rand() % 360);
        }
    }
}

/*
void CAngls::generateRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        data[i] = static_cast<double>(rand() % 360);
    }
}
*/