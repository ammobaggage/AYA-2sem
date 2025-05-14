#include <iostream>
#include <vector>
using namespace std;
class Circle {
protected:
	double radius;
public:
	Circle(double pop1) : radius(pop1) {}
	virtual void print() {
		cout << "Радиус круга | Первая полуось эллипса: " << radius << endl;
	}
	virtual ~Circle() = default;
};
class Ellipse : public Circle {
	double poluos;
public:
	Ellipse(double pop1, double pop2) : Circle(pop1), poluos(pop2) {}
	void print() override {
		Circle::print();
		cout << "Вторая полуось эллипса: " << poluos << endl;
	}
};
int main() {
	setlocale(LC_ALL, "RUS");
	Circle circle(12.0);
	Ellipse ellipse(12.0, 8.0);
	cout << "Cтатический полиморфизм:" << endl;
	circle.print();
	ellipse.print();
	cout << "\nДиамический полиморфизм:" << endl;
	Circle* dp_circle = &circle;
	Circle* dp_ellipse = &ellipse;
	dp_circle->print();
	dp_ellipse->print();
	vector<Circle*> shapes;
	shapes.push_back(&circle);
	shapes.push_back(&ellipse);
	cout << "\nВсе объекты:" << endl;
	for (auto& shape : shapes) {
		shape->print();
	}
	return 0;
}