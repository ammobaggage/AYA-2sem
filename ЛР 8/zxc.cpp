#include <iostream>
#include "MyUnique.cpp"
using namespace std;

class MyPoint {
	double x, y;

public:
	MyPoint(double x, double y) : x(x), y(y) {}
	void print() const {
		cout << "����� ( " << x << ", " << y << " )" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	
	MyUnique<int> ptr1(new int(5));
	cout << "ptr1 = " << *ptr1 << endl;
	MyUnique<int> ptr2 = move(ptr1);
	cout <<"����� �����������: ptr2 = " << *ptr2 << " (ptr1 ����)" << endl;
	
	auto pointPtr = Make_MyUnique<MyPoint>(23.06, 2025);
	pointPtr->print();
	MyUnique<MyPoint> movedpointPtr = move(pointPtr);
	cout << "����� �����������: ";
	movedpointPtr -> print();
	return 0;
}