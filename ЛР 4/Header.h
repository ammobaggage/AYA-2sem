#pragma once
#include <string>
using namespace std;
class Student {
	string name;
	string group;
	string number;
	int grades[4];
public:
	Student();
	Student(const string& name, const string& grp, const string& num, const int
		g[4]);
	Student(const Student& copy);
	Student(Student&& cmove) noexcept;
	Student& operator=(const Student& givecopy);
	Student& operator=(Student&& givemove) noexcept;
	double getGrade() const;
	friend ostream& operator<<(ostream& outS, const Student& student);
	bool operator<(const Student& other) const;
};