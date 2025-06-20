#include <iostream>
#include <memory>
#include "Unique.cpp"
using namespace std;

// Пример класса для демонстрации
class MyPoint {
	double x, y;

public:
	MyPoint(double x, double y) : x(x), y(y) {}
	void print() const {
		cout << "Point(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	// Демонстрация MyUnique с базовым типом
	MyUnique<int> ptr1(new int(52));
	cout << *ptr1 << endl;
	// Демонстрация перемещения
	MyUnique<int> ptr2 = move(ptr1);
	cout << *ptr2 << endl;
	//cout << *ptr1 << endl; // Ошибка: ptr1 теперь пуст
	// Демонстрация с пользовательским классом
	auto pointPtr = Make_MyUnique<MyPoint>(228, 20.25);
	pointPtr->print();
	MyUnique<MyPoint> moved = move(pointPtr); // Перемещение разрешено
	moved->print();
	return 0;
}