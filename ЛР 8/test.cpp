#include <iostream>
#include "MyShared.cpp"
using namespace std;

class Territory {
	int x, y;

public:
	Territory(int x, int y) : x(x), y(y) {}
	
	void print() const {
		cout << "Территория: " << x << " на " << y << " метров" << endl;
	}
	
	int area() const {
		return x * y;
	}
};
int main() {
	setlocale(LC_ALL, "RUS");
	
	MyShared<int> shared1(new int(5));
	cout << *shared1 << ", кол-во указателей: " << shared1.use_count() << endl;
	MyShared<int> shared2 = shared1;
	cout << *shared2 << ", кол-во указателей после копирования: " << shared1.use_count() << endl;
	
	auto terPtr = Make_MyShared<Territory>(200, 165);
	terPtr->print();
	cout << "Площадь территории: " << terPtr->area() << "м^2 " << endl;
	
	auto terPtr2 = terPtr;
	cout << "Кол-во указателей после копирования: " << terPtr.use_count() << endl;
	auto terPtr3 = move(terPtr2);
	cout << "Кол-во указателей после перемещения: " << terPtr.use_count() << endl;

	return 0;
}
