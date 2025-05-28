#pragma once
#include <iostream>
#include <cmath>

class CVects {
    
    struct Vector {
        double x;
        double y;
    };
    Vector* data;
    int size;

public:
    
    CVects(int n = 0);
    CVects(const CVects& other);
    CVects(CVects&& other) noexcept;

    ~CVects();
    
    CVects& operator=(const CVects& other); //Копирование
    CVects& operator=(CVects&& other) noexcept; //Перемещение

    CVects& operator++(); 
    CVects operator++(int); 
    CVects& operator--(); 
    CVects operator--(int); 

    friend std::ostream& operator<<(std::ostream& os, const CVects& v);

    friend CVects operator+(const CVects& v, const class CAngls& a);
    friend CVects operator+(const class CAngls& a, const CVects& v);
    friend class CAngls operator-(const CVects& v1, const CVects& v2);

    
    void readFromFile(std::istream& is);
    //void generateRandom();

    int getSize() const { return size; }
    const Vector* getData() const { return data; }
};

