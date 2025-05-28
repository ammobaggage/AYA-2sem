#pragma once
#include <iostream>
#include "CVects.h"

class CAngls {

    double* data;
    int size;

public:
    
    CAngls(int n = 0);
    CAngls(const CAngls& other);
    CAngls(CAngls&& other) noexcept; 

    ~CAngls();

    CAngls& operator=(const CAngls& other); //Копирование
    CAngls& operator=(CAngls&& other) noexcept; //Премещение

    CAngls& operator++(); 
    CAngls operator++(int);
    CAngls& operator--(); 
    CAngls operator--(int);

    friend std::ostream& operator<<(std::ostream& os, const CAngls& a);

    friend class CVects operator+(const class CVects& v, const CAngls& a);
    friend class CVects operator+(const CAngls& a, const class CVects& v);
    friend CAngls operator-(const class CVects& v1, const class CVects& v2);

    void readFromFile(std::istream& is);
    //void generateRandom();

    int getSize() const { return size; }
    const double* getData() const { return data; }
};
