#include <iostream>
#include <memory>
using namespace std;

template<class T>
class MyUnique {
	T* p = nullptr;

public:
	// �����������, ����������� ����� ���������
	explicit MyUnique(T* ptr) : p(ptr) {}
	// ����������
	~MyUnique() {
		delete p;
	}
	// ������� ����������� �����������
	MyUnique(const MyUnique&) = delete;
	// ������� �������� ������������ � ������������
	MyUnique& operator=(const MyUnique&) = delete;
	// ����������� �����������
	MyUnique(MyUnique&& move) noexcept : p(move.p) {
		move.p = nullptr;
	}
	// �������� ������������ � ������������
	MyUnique& operator=(MyUnique&& g_m) noexcept {
		if (this != &g_m) {
			delete p;
			p = g_m.p;
			g_m.p = nullptr;
		}
		return *this;
	}
	// ����� get, ������������ ����� ���������
	T* get() const {
		return p;
	}
	// ���������� ��������� *
	T& operator*() {
		return *p;
	}
	// ���������� ��������� ->
	T* operator->() {
		return p;
	}
};
// ������� ��� �������� MyUnique � ���������� ������ ����������
template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
	return MyUnique<T>(new T(forward<Args>(args)...));
}
