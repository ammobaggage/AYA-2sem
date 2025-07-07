#include <iostream>
using namespace std;

template<class T>
class MyUnique {
	T *p = nullptr;

public:
	MyUnique(T *ptr) : p(ptr) {}
	
	~MyUnique() { delete p; }
	
	MyUnique(const MyUnique&) = delete;
	MyUnique& operator=(const MyUnique&) = delete;
	
	MyUnique(MyUnique&& move) : p(move.p) {
		move.p = nullptr;
	}
	
	MyUnique& operator=(MyUnique&& g_m) {
		if (this != &g_m) {
			delete p;
			p = g_m.p;
			g_m.p = nullptr;
		}
		return *this;
	}
	
	T* get() const { return p; } //сырой указатенль
	T& operator*() { return *p; } //разыменовывание
	T* operator->() { return p; } //для доступа к полям класса
};

template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
	return MyUnique<T>(new T(forward<Args>(args)...));
}
