#include <iostream>
#include <future>
using namespace std;


void thread_operation(const string& name, double* num1, double* num2, int size, char sign) {
	for (int i = 0; i < size; i++) {
		cout << name << "\n";
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
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	int n1, n2, n3;
	cout << "������� 1)���-�� �������� ���������, 2)�������� ��������, 3)���-�� �����  \n";
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

	future<void> thread1 = async(thread_operation, "�����1", num11, num12, n1, '*');
	future<void> thread2 = async(thread_operation, "�����2", num21, num22, n2, '+');
	thread1.get();
	cout << "\n�����1 ��������\n" << endl;
	thread2.get();
	cout << "\n�����2 ��������\n" << endl;

	future<void> thread3 = async(thread_operation, "�����3", num11, num12, n3, 'r');
	thread3.get();
	cout << "\n�����3 ��������\n" << endl;

	cout << "\n��� ������ ���������\n";
	return 0;
}