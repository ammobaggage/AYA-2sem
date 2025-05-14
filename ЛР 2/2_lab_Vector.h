#pragma once
#include <sstream>;
using namespace std;

class Vector {
	double* p = nullptr;
	int n = 0;
public:
	
	Vector();
	Vector(double* p, int n);
	Vector(const Vector& vcopy);
	Vector(Vector&& vmove);
	double& operator[](int index);
	Vector& operator =(const Vector& vgive_copy);
	Vector& operator =(Vector&& vgive_move);
	~Vector();
	double operator*(const double* arr) const;
	friend ostream& operator<<(ostream& outS, const Vector& V);
	friend istream& operator>>(istream& inS, const Vector& V);
};

