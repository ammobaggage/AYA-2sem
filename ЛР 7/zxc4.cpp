#include <iostream>
#include <mutex>
#include <future>
using namespace std;

mutex mute, mute1;
void thread_operation(const string& name, double* num1, double* num2, int size, char sign) {
	mute.lock();
	for (int i = 0; i < size; i++) {
		cout << name << '\n';
		this_thread::sleep_for(chrono::milliseconds(100));
		switch (sign) {
		case '+':
			cout << num1[i] << " + " << num2[i] << " = " << num1[i] + num2[i] << '\n';
			break;

		case '*':
			cout << num1[i] << " * " << num2[i] << " = " << num1[i] * num2[i] << '\n';
			break;

		case 'r':
			cout << rand() % 1000 / 100.0 << '\n';
			break;
		}
	}
	mute.unlock();
}
int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int n1, n2, n3;
	cout << "Введите 1)Кол-во операций умножения, 2)Операций сложения, 3)Кол-во чисел  \n";
	cin >> n1 >> n2 >> n3;
	double* num11 = new double[n1];
	double* num12 = new double[n1];
	double* num21 = new double[n2];
	double* num22 = new double[n2];
	
	for (int i = 0; i < n1; i++) {
		num11[i] = rand() % 1000 / 100.0;
		num12[i] = rand() % 1000 / 100.0;
	}
	for (int i = 0; i < n2; i++) {
		num21[i] = rand() % 1000 / 100.0;
		num22[i] = rand() % 1000 / 100.0;
	}

	future<void> thread1 = async(thread_operation, "Поток1", num11, num12, n1, '*');
	future<void> thread2 = async(thread_operation, "Поток2", num21, num22, n2, '+');
	future<void> thread3 = async(thread_operation, "Поток3", nullptr, nullptr, n3, 'r');
	
	thread1.get();
	thread2.get();
	thread3.get();

	cout << "Все потоки завершены\n";
	return 0;
}