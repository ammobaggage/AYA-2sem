#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() {
    list<Student> studentsList;
    set<Student> studentsSet;
    unordered_set<Student> studentsUnSet;

    ifstream inF("input.txt");
    ofstream outF("output.txt");
    if (inF.is_open()) {
        string name, group, recordNum;
        int grades[4];

        while (inF >> name >> group >> recordNum >> grades[0] >> grades[1] >> grades[2] >> grades[3]) {
            Student student(name, group, recordNum, grades);
            studentsList.emplace_back(name, group, recordNum, grades);
        }
        inF.close();
    }
    else {
        cerr << "шкибиди файл" << endl;
        return 1;
    }

    outF << "Список студентов (list):" << endl;
    for (const auto& student : studentsList) {
        outF << student << endl;
    }
    outF << endl;
    
    copy(studentsList.begin(), studentsList.end(), inserter(studentsSet, studentsSet.begin()));
    outF << "Список студентов (set):" << endl;
    for (const auto& student : studentsSet) {
        outF << student << endl;
    }
    outF << endl;
    
    copy(studentsList.begin(), studentsList.end(), inserter(studentsUnSet, studentsUnSet.begin()));
    outF << "Список студентов (unordered_set):" << endl;
    for (const auto& student : studentsSet) {
        outF << student << endl;
    }
    outF << endl;
    outF.close();
    return 0;
}