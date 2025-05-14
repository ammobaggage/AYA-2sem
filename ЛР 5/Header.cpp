#include "Header.h"
#include <numeric>
#include <iostream>

Student::Student() : name(""), group(""), number(""), grades{ 0, 0, 0, 0 } {}

Student::Student(const string& name, const string& grp, const string& num, const int g[4]) : name(name), group(grp), number(num) {
    for (int i = 0; i < 4; ++i) { grades[i] = g[i]; }
}

Student::Student(const Student& copy) : name(copy.name), group(copy.group), number(copy.number) {
    for (int i = 0; i < 4; ++i) {
        grades[i] = copy.grades[i];
    }
}

Student::Student(Student&& cmove) noexcept : name(move(cmove.name)), group(move(cmove.group)), number(move(cmove.number)) {
    for (int i = 0; i < 4; ++i) {
        grades[i] = cmove.grades[i];
    }
}

Student& Student::operator=(const Student& givecopy) {
    if (this != &givecopy) {
        name = givecopy.name;
        group = givecopy.group;
        number = givecopy.number;
        for (int i = 0; i < 4; ++i) { grades[i] = givecopy.grades[i]; }
    }
    return *this;
}

Student& Student::operator=(Student&& givemove) noexcept {
    if (this != &givemove) {
        name = move(givemove.name);
        group = move(givemove.group);
        number = move(givemove.number);
        for (int i = 0; i < 4; ++i) { grades[i] = givemove.grades[i]; }
    }
    return *this;
}

double Student::getGrade() const {
    return accumulate(begin(grades), end(grades), 0.0) / 4.0;
}

ostream& operator<<(ostream& outS, const Student& student) {
    outS << "ФИО: " << student.name << ", группа: " << student.group << ", номер зачетки: " << student.number << ", оценки: ";
    for (int grade : student.grades) { outS << grade << " "; }
    outS << ", cр. балл: " << student.getGrade();
    return outS;
}

bool Student::operator<(const Student& other) const {
    return getGrade() < other.getGrade();
}

bool Student::operator==(const Student& other) const {
    return name == other.name && group == other.group && number == other.number && grades[0] == other.grades[0] 
        && grades[1] == other.grades[1] && grades[2] == other.grades[2] && grades[3] == other.grades[3];
}