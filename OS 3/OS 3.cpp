//#include <iostream>
//#include <windows.h>
//#include <process.h>
//using namespace std;
//
//
//
//CRITICAL_SECTION cs;
//
//
//DWORD WINAPI work(double* b)
//{
//
//	cout << " interval : ";
//
//	int i_;
//	cin >> i_;
//
//	double* a = new double[b[0]];
//
//
//	double* c = new double[b[0]];
//
//
//	for (int i = 0; i < b[0]; i++) {
//		a[i] = b[i + 2];
//	}
//
//
//	int count = 0;
//
//	for (int i = 0; i < b[0]; i++) {
//		if (a[i] < (int)b[1]) {
//			c[count] = a[i];
//			count++;
//		}
//	}
//	for (int i = 0; i < b[0]; i++) {
//		if (a[i] >= (int)b[1]) {
//			c[count] = a[i];
//			count++;
//		}
//	}
//
//	for (int i = 0; i < b[0]; i++) {
//		b[i + 2] = c[i];
//	}
//
//
//	cout << " b : ";
//	for (int i = 2; i < b[0] + 2; i++) {
//		cout << b[i] << " ";
//		Sleep(i_ * 1000);
//	}
//
//	cout << endl;
//
//
//
//
//	SetEvent(Event_);
//
//	return 0;
//
//}
//
//DWORD WINAPI MultElement(double* b)
//{
//	double mult = b[2];
//
//
//	double* a = new double[b[0]];
//
//	for (int i = 0; i < b[0]; i++) {
//		a[i] = b[i + 3];
//	}
//
//	for (int i = a[1]; i < b[0]; i++) {
//		mult *= a[i];
//	}
//
//
//
//	EnterCriticalSection(&cs);
//
//	cout << " m : ";
//	cout << mult;
//
//	b[2] = mult;
//
//	LeaveCriticalSection(&cs);
//
//	return 0;
//
//}
//
//int main() {
//	HANDLE	hThread_1;
//	HANDLE	hThread_2;
//	DWORD	IDThread_1;
//	DWORD	IDThread_2;
//
//
//	HANDLE Event_ = CreateEvent(NULL, FALSE, FALSE, NULL);
//	HANDLE Event_1 = CreateEvent(NULL, FALSE, FALSE, NULL);
//
//	InitializeCriticalSection(&cs);
//
//	int n = 0;
//	int l = 0;
//
//	double mult = 1;
//
//	cout << " Quantity numbers : ";
//
//	cin >> n;
//
//	double* a = new double[n];
//
//
//	cout << " Massive : ";
//
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	cout << " n : ";
//
//	cout << n << endl;
//
//	cout << " f massive : ";
//
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//
//	cout << endl;
//
//
//	int A;
//
//	cout << " A : ";
//
//	cin >> A;
//
//	double* b = new double[n + 2];
//
//	for (int i = 2; i <= n + 1; i++) {
//		b[i] = a[i - 2];
//	}
//
//	b[0] = n;
//	b[1] = A;
//
//
//	hThread_1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)work, b, CREATE_SUSPENDED, &IDThread_1);
//	if (hThread_1 == NULL)
//		return GetLastError();
//
//
//	int k;
//
//
//	cout << " k : ";
//
//
//	cin >> k;
//
//
//	ResumeThread(hThread_1);
//
//	DWORD dwResult = WaitForSingleObject(Event_, INFINITE);
//
//
//	double* c = new double[n + 3];
//
//
//
//	if (dwResult == WAIT_OBJECT_0) {
//		cout << " final massive : ";
//
//		for (int i = 2; i < n + 2; i++) {
//			cout << b[i] << " ";
//		}
//
//		cout << " k massive : ";
//
//		for (int i = 2 + n - k; i < n + 2; i++) {
//			cout << b[i] << " ";
//		}
//
//		cout << endl;
//
//
//		for (int i = 3; i <= n + 1; i++) {
//			c[i] = b[i - 1];
//		}
//
//		c[0] = n;
//		c[1] = A;
//		c[2] = mult;
//
//	}
//
//	else {
//		std::cerr << "Ошибка при ожидании события." << std::endl;
//	}
//
//
//	hThread_2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MultElement, c, CREATE_SUSPENDED, &IDThread_2);
//	if (hThread_1 == NULL)
//		return GetLastError();
//
//	ResumeThread(hThread_2);
//
//	EnterCriticalSection(&cs);
//
//	cout << c[2];
//
//	LeaveCriticalSection(&cs);
//		
//	CloseHandle(hThread_1);
//    CloseHandle(hThread_2);
//
//	DeleteCriticalSection(&cs);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include <iostream>
//#include <windows.h>
//
//CRITICAL_SECTION cs;
//int k, A;
//long long result = 1;
//
//
//HANDLE event2 = CreateEvent(NULL, FALSE, FALSE, NULL);
//HANDLE event3 = CreateEvent(NULL, FALSE, FALSE, NULL);
//
//// Функция для потока 2
//DWORD WINAPI Thread2Function(LPVOID lpParam) {
//	int* dataArray = reinterpret_cast<int*>(lpParam);
//
//	WaitForSingleObject(event2, INFINITE);
//
//	for (int i = 0; i < k; ++i) {
//		if (dataArray[i] < A) {
//			int temp = dataArray[i];
//			dataArray[i] = dataArray[k];
//			dataArray[k] = temp;
//			++k;
//		}
//	}
//
//	SetEvent(event2);
//	return 0;
//}
//
//// Функция для потока 3
//DWORD WINAPI Thread3Function(LPVOID lpParam) {
//	int* dataArray = reinterpret_cast<int*>(lpParam);
//
//	WaitForSingleObject(event3, INFINITE);
//
//	EnterCriticalSection(&cs);
//	for (int i = k; i < dataArraySize; ++i) {
//		result *= dataArray[i];
//	}
//	LeaveCriticalSection(&cs);
//
//	return 0;
//}
//
//int main() {
//	k = 0;
//	A = 0;
//	int dataArraySize;
//
//	std::cout << "Введите размер массива: ";
//	std::cin >> dataArraySize;
//	int* dataArray = new int[dataArraySize];
//
//	InitializeCriticalSection(&cs);
//
//	HANDLE event2 = CreateEvent(NULL, FALSE, FALSE, NULL);
//	HANDLE event3 = CreateEvent(NULL, FALSE, FALSE, NULL);
//
//	// Создание и запуск потока 2
//	HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, dataArray, 0, NULL);
//
//	// Ввод данных в первом потоке
//	for (int i = 0; i < dataArraySize; ++i) {
//		std::cout << "Введите элемент " << i << ": ";
//		std::cin >> dataArray[i];
//	}
//
//	std::cout << "Введите значение A: ";
//	std::cin >> A;
//
//	// Запуск потока 2
//	SetEvent(event2);
//
//	// Создание и запуск потока 3
//	HANDLE hThread3 = CreateThread(NULL, 0, Thread3Function, dataArray, 0, NULL);
//
//	// Ожидание завершения потока 3
//	WaitForSingleObject(hThread3, INFINITE);
//
//	// Вывод результата из потока 3
//	std::cout << "Итоговое произведение: " << result << std::endl;
//
//	// Закрытие и освобождение ресурсов
//	CloseHandle(event2);
//	CloseHandle(event3);
//	CloseHandle(hThread2);
//	CloseHandle(hThread3);
//	DeleteCriticalSection(&cs);
//
//	delete[] dataArray; // Освобождение памяти
//
//	return 0;
//}


















#include <iostream>
#include <windows.h>
#include <vector>
#include <process.h>
using namespace std;

CRITICAL_SECTION cs;
int k;
int A;
long long result = 1;

HANDLE Event_1 = CreateEvent(NULL, FALSE, FALSE, NULL);
HANDLE Event_2 = CreateEvent(NULL, FALSE, FALSE, NULL);

DWORD WINAPI Thread2Function(LPVOID lpParam) {
	vector<double>& a = *static_cast<vector<double>*>(lpParam);

	cout << " interval : ";
	int i_;
	cin >> i_;

	cout << endl;

	//WaitForSingleObject(Event_1, INFINITE);

	/*for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] < A) {
			std::swap(a[i], a[k]);
			++k;
		}
	}*/

	/*vector<double> c;

	int count = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] < A) {
			c[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= A) {
			c[count] = a[i];
			count++;
		}
	}

	for (int i = 0; i < c.size(); i++) {
		a[i] = c[i];
	}*/



	vector<double> smaller;
	vector<double> greater;

	for (double num : a) {
		if (num < A) {
			smaller.push_back(num);
		}
		else {
			greater.push_back(num);
		}
	}

	a.clear();

	a.insert(a.end(), greater.begin(), greater.end());
	a.insert(a.end(), smaller.begin(), smaller.end());


		cout << " a : ";
			for (int i = 0; i < a.size(); i++) {
				cout << a[i] << " ";
				Sleep(i_ * 1000);
			}
		
			cout << endl;

	SetEvent(Event_1);
	return 0;
}

DWORD WINAPI Thread3Function(LPVOID lpParam) {
	vector<double>& a = *static_cast<vector<double>*>(lpParam);

	EnterCriticalSection(&cs);

	WaitForSingleObject(Event_2, INFINITE);

	for (size_t i = k; i < a.size(); ++i) {
		result *= a[i];
	}

	LeaveCriticalSection(&cs);

	return 0;
}

int main() {
	k = 0;
	A = 0;
	std::vector<double> a;

	setlocale(LC_ALL, "RUSSIAN");

	cout << " Введите размер массива: ";
	int n;
	cin >> n;

	cout << " Введите элементы : ";
	for (int i = 0; i < n; ++i) {
		double element;
		cin >> element;
		a.push_back(element);
	}

	cout << " Размер массива : " << n;

	cout << endl;

	cout << " Массив : ";
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}

	cout << endl;

	InitializeCriticalSection(&cs);

	HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, &a, CREATE_SUSPENDED, NULL);

	cout << " Введите значение A : ";
	cin >> A;
	cout << " Введите значение k : ";
	cin >> k;
	cout << endl;

	ResumeThread(hThread2);

	HANDLE hThread3 = CreateThread(NULL, 0, Thread3Function, &a,0 /*CREATE_SUSPENDED*/, NULL);


	WaitForSingleObject(Event_1, INFINITE);

	cout << " Массив итог : ";
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}

	cout << endl;

	//ResumeThread(hThread3);

	SetEvent(Event_2);


	EnterCriticalSection(&cs);

	cout << "Итоговое произведение: " << result << std::endl;

	LeaveCriticalSection(&cs);

	WaitForSingleObject(hThread3, INFINITE);

	CloseHandle(Event_1);
	CloseHandle(Event_2);
	CloseHandle(hThread2);
	CloseHandle(hThread3);
	DeleteCriticalSection(&cs);

	return 0;
}

