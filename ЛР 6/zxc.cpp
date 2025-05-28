#include <stdexcept>
#include <iostream>
using namespace std;

class PointException : public out_of_range {

    double x, y, z;

public:
    PointException(const string& msg, double x, double y, double z) : out_of_range(msg), x(x), y(y), z(z) {}

    void print() const {
        cerr << "Некорректная точка: (" << x << ", " << y << ", " << z << ")\n" << "Ошибка: " << what() << endl;
    }
};

class UnitCubePoint {
    double x, y, z;

    void validate() const {
        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1)
            throw PointException("Точка за пределами куба", x, y, z);
    }
public:
    UnitCubePoint(double x, double y, double z) : x(x), y(y), z(z) {
        validate();
    }

    void print() const {
        cout << "Точка: (" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    try {
        UnitCubePoint p1(0.5, 0.5, 0.5);
        p1.print();
    }
    catch (const PointException& e) {
        e.print();
    }

    try {
        UnitCubePoint p2(1.1, 0.5, 0.5);
        p2.print();
    }
    catch (const PointException& e) {
        e.print();
    }
}
