#pragma once
#include <string>
#include <functional>
using namespace std;

class Student {

    string name;
    string group;
    string number;
    int grades[4];

public:
    Student();
    Student(const string& name, const string& grp, const string& num, const int g[4]);
    Student(const Student& copy);
    Student(Student&& cmove) noexcept;
    Student& operator=(const Student& givecopy);
    Student& operator=(Student&& givemove) noexcept;
    double getGrade() const;
    friend ostream& operator<<(ostream& outS, const Student& student);
    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;
    friend struct hash<Student>;
};

namespace std { 
    template<>
    struct hash<Student> {
        size_t operator()(const Student& s) const {
            hash<string> hash_s;
            size_t h1 = hash_s(s.name);
            size_t h2 = hash_s(s.group);
            size_t h3 = hash_s(s.number);
            int sum_grades = s.grades[0] + s.grades[1] + s.grades[2] + s.grades[3];
            return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (sum_grades << 3);
        }
    };
}