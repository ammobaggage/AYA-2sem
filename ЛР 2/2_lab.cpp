#include <Windows.h>
#include "Vector.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	setlocale(LC_ALL, "RUS");

	ifstream inF("input.txt");
	if (!inF.is_open()) {
		cerr << "input.txt не найден((" << endl;
		return 1;
	}

	int n;
	inF >> n; 

	double* arr1 = new double[n];
	double* arr2 = new double[n];
	for (int i = 0; i < n; ++i) {
		inF >> arr1[i];
	}
	for (int i = 0; i < n; ++i) {
		inF >> arr2[i];
	}
	inF.close();

	Vector vec1(arr1, n);
	
	double result = vec1 * arr2;
	
	ofstream outF("output.txt");
	if (!outF.is_open()) {
		cerr << "Ошибка открытия файла output.txt!" << endl;
		return 1;
	}
	outF << "Объект 'Вектор': " << vec1 << endl;
	outF << "Результат скалярного произведения векторов: " << result << endl;
	outF.close();
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
}
