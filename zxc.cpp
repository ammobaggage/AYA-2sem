#include <iostream>
#include <memory>
#include "Unique.cpp"
using namespace std;

// ������ ������ ��� ������������
class MyPoint {
	double x, y;

public:
	MyPoint(double x, double y) : x(x), y(y) {}
	void print() const {
		cout << "Point(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	// ������������ MyUnique � ������� �����
	MyUnique<int> ptr1(new int(52));
	cout << *ptr1 << endl;
	// ������������ �����������
	MyUnique<int> ptr2 = move(ptr1);
	cout << *ptr2 << endl;
	//cout << *ptr1 << endl; // ������: ptr1 ������ ����
	// ������������ � ���������������� �������
	auto pointPtr = Make_MyUnique<MyPoint>(228, 20.25);
	pointPtr->print();
	MyUnique<MyPoint> moved = move(pointPtr); // ����������� ���������
	moved->print();
	return 0;
}