#include <iostream>
#include <memory>
using namespace std;

template<class T>
class MyUnique {
	T* p = nullptr;

public:
	// Конструктор, принимающий сырой указатель
	explicit MyUnique(T* ptr) : p(ptr) {}
	// Деструктор
	~MyUnique() {
		delete p;
	}
	// Удаляем конструктор копирования
	MyUnique(const MyUnique&) = delete;
	// Удаляем оператор присваивания с копированием
	MyUnique& operator=(const MyUnique&) = delete;
	// Конструктор перемещения
	MyUnique(MyUnique&& move) noexcept : p(move.p) {
		move.p = nullptr;
	}
	// Оператор присваивания с перемещением
	MyUnique& operator=(MyUnique&& g_m) noexcept {
		if (this != &g_m) {
			delete p;
			p = g_m.p;
			g_m.p = nullptr;
		}
		return *this;
	}
	// Метод get, возвращающий сырой указатель
	T* get() const {
		return p;
	}
	// Перегрузка оператора *
	T& operator*() {
		return *p;
	}
	// Перегрузка оператора ->
	T* operator->() {
		return p;
	}
};
// Функция для создания MyUnique с переменным числом параметров
template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
	return MyUnique<T>(new T(forward<Args>(args)...));
}
