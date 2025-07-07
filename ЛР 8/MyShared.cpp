#include <iostream>
using namespace std;

template<class T>
class MyShared {
	T* p = nullptr;
	int* count = nullptr;

	void clear() {
		if (count && --(*count) == 0) {
			delete p;
			delete count;
		}
		p = nullptr;
		count = nullptr;
	}

public:
	MyShared(T* ptr = nullptr) : p(ptr), count(ptr ? new int(1) : nullptr) {}
	
	~MyShared() { clear(); }
	
	MyShared(const MyShared& copy) : p(copy.p), count(copy.count) {
		if (count) { 
			++(*count); 
		}
	}
	
	MyShared& operator=(const MyShared& c_m) {
		if (this != &c_m) {
			clear();
			p = c_m.p;
			count = c_m.count;
			if (count) { 
				++(*count); 
			}
		}
		return *this;
	}
	
	MyShared(MyShared&& move) : p(move.p), count(move.count) {
		move.p = nullptr;
		move.count = nullptr;
	}

	MyShared& operator=(MyShared&& g_m) {
		if (this != &g_m) {
			clear();
			p = g_m.p;
			count = g_m.count;
			g_m.p = nullptr;
			g_m.count = nullptr;
		}
		return *this;
	}
	
	T* get() const { return p; } //сырой указатель
	T& operator*() { return *p; } //разыменовывание
	T* operator->() { return p; } //для доступа к полям класса
	
	int use_count() const {
		return count ? *count : 0;
	}
};

template<typename T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
	return MyShared<T>(new T(forward<Args>(args)...));
}