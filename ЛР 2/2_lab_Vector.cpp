#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
	p = nullptr;
	n = 0;
	cout << "Vector()" << endl;
}

Vector::Vector(double* p, int n)
{
	this->n = n; 
	this->p = new double[n]; 
	for (int i = 0; i < n; i++) this->p[i] = p[i];
	cout << "Vector(double *p, int n)" << endl;
}

Vector::Vector(const Vector& vcopy)
{
	n = vcopy.n;
	p = new double[n];
	for (int i = 0; i < n; i++)
		p[i] = vcopy.p[i];
	cout << "Vector(const Vector & vcopy)" << endl;
}

Vector::Vector(Vector&& vmove)
{
	swap(p, vmove.p);
	swap(n, vmove.n);
	cout << "Vector(Vector&& vmove)" << endl;
}

double& Vector::operator[](int index)
{
	return p[index];
}

Vector& Vector::operator=(const Vector& vgive_copy)
{
	if (this != &vgive_copy)
	{
		n = vgive_copy.n;
		if (p != nullptr)
		{
			delete[] p;
			p = new double[n];
			for (int i = 0; i < n; i++) p[i] = vgive_copy.p[i];
		}
	}
	cout << "Vector & operator=(const Vector& vgive_copy)" << endl;
	return *this;
}

Vector& Vector::operator=(Vector&& vgive_move)
{
	if (this != &vgive_move)
	{
		delete[]p;
		p = vgive_move.p;
		n = vgive_move.n;
		vgive_move.p = nullptr;
		vgive_move.n = 0;
	}
	cout << "Vector & operator =(Vector&& vgive_move)" << endl;
	return *this;
}

Vector::~Vector()
{
	cout << "~Vector()" << endl;
	if (p != nullptr) delete[] p; 
}

double Vector::operator*(const double* arr) const
{
	if (!arr) {
		throw invalid_argument("Ïåðåäàí íóëåâîé óêàçàòåëü (nullptr)");
	}

	double result = 0.0;
	for (int i = 0; i < n; ++i) {
		result += p[i] * arr[i];
	}
	return result;
}

ostream& operator<<(ostream& outS, const Vector& v)
{
	for (int i = 0; i < v.n; ++i) {
		outS << v.p[i] << " ";
	}
	return outS;
}

istream& operator>>(istream& inS, const Vector& v)
{
	for (int i = 0; i < v.n; ++i) {
		inS >> v.p[i];
	}
	return inS;
}
