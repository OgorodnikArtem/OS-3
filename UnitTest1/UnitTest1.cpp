#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../OS 3/OS 3.cpp"
#include <thread>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestThread2Function)
		{

			A = 0;
			k = 0;
			std::vector<double> testVector;
			cout << " ¬ведите размер массива: ";
			int n;
			cin >> n;

			double element = 1.0;

			cout << " ¬ведите элементы : ";
			for (int i = 0; i < n; ++i) {
				cout << element;
				testVector.push_back(element);
				element += 1.0;
			}

			HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, &testVector, CREATE_SUSPENDED, NULL);

			A = 3;

			k = 2;

			i_ = 1;

			ResumeThread(hThread2);

			// Call Thread2Function and check if the vector is sorted as expected


			WaitForSingleObject(Event_1, INFINITE);

			// Add assertions to check the expected result
			Assert::AreEqual(3.0, testVector[0]);  // Largest element
			Assert::AreEqual(4.0, testVector[1]);
			Assert::AreEqual(5.0, testVector[2]);
			Assert::AreEqual(1.0, testVector[3]);
			Assert::AreEqual(2.0, testVector[4]);  // Smallest element
		}

		TEST_METHOD(TestThread3Function)
		{
			std::vector<double> testVector = { 3.0, 4.0, 5.0, 1.0, 2.0 };
			k = 2;

			// Call Thread3Function and check if the result is calculated as expected
			Thread3Function(&testVector);

			// Add assertions to check the expected result
			Assert::AreEqual(10.0, (double)result);  // 4.0 * 2.5
		}

		TEST_METHOD(Thread2FunctionTest)
		{
			std::vector<double> testVector = { 3.0, 1.0, 5.0, 2.0, 4.0 };
			int testK = 2;
			int testA = 3;
			int testInterval = 1; // 1 second interval

			HANDLE Event_1 = CreateEvent(NULL, FALSE, FALSE, NULL);
			HANDLE Event_2 = CreateEvent(NULL, FALSE, FALSE, NULL);

			DWORD threadId;
			HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, &testVector, CREATE_SUSPENDED, &threadId);

			SetEvent(Event_1); // Signal Event_1 to allow Thread2Function to execute

			std::thread([&]() {
				WaitForSingleObject(Event_1, INFINITE);

				// Simulate user input
				std::this_thread::sleep_for(std::chrono::seconds(testInterval));
				std::cout << " interval : " << testInterval << std::endl;

				// Simulate user input
				std::this_thread::sleep_for(std::chrono::seconds(testInterval));
				std::cout << " a : ";
				for (int i = 0; i < testVector.size(); i++) {
					std::cout << testVector[i] << " ";
				}
				std::cout << std::endl;

				SetEvent(Event_2); // Signal Event_2 to allow Thread3Function to execute
				}).detach();

				ResumeThread(hThread2);
				WaitForSingleObject(hThread2, INFINITE);

				Assert::AreEqual(3.0, testVector[0]);
				Assert::AreEqual(1.0, testVector[1]);
				Assert::AreEqual(2.0, testVector[2]);
				Assert::AreEqual(5.0, testVector[3]);
				Assert::AreEqual(4.0, testVector[4]);

				CloseHandle(Event_1);
				CloseHandle(Event_2);
				CloseHandle(hThread2);
		}
	};
}