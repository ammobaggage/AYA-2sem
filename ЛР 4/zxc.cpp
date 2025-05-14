#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Header.h"
using namespace std;

int main() {

	list<Student> studentsList;
	ifstream inF("input.txt");
	ofstream outF("output.txt");

	if (inF.is_open()) {
		string name, group, recordNum;
		int grades[4];
		while (inF >> name >> group >> recordNum >> grades[0] >> grades[1] >>
			grades[2] >> grades[3]) {
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

	vector<Student> studentsVector;
	copy(studentsList.begin(), studentsList.end(), back_inserter(studentsVector));
	outF << "Копированный список студентов (vector):" << endl;
	for (const auto& student : studentsVector) {
		outF << student << endl;
	}

	studentsList.sort();
	outF << "\nСписок после сортировки (list):" << endl;
	for (const auto& student : studentsList) {
		outF << student << endl;
	}

	outF << endl;
	outF.close();

	return 0;
}