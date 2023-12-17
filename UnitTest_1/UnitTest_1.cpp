#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include <windows.h>

#include "../OS 3/OS 3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Process1Test)
		{
			// Arrange
			std::vector<double> a = { 1, 2, 3, 4, 5 }; // Adjust the input values as needed

			A = 3;

			k = 2;

			// Act
			DWORD IDThread;
			HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, &a, NULL, &IDThread);

			i_ = 1;

			WaitForSingleObject(hThread2, INFINITE);

			// Assert
			Assert::AreEqual(5.0, a[0]); // Adjust the expected values based on your input
			Assert::AreEqual(8.0, a[1]);
			Assert::AreEqual(2.0, a[2]);
			Assert::AreEqual(3.0, a[3]);
			Assert::AreEqual(1.0, a[4]);
		}

		TEST_METHOD(Process2Test)
		{
			// Arrange
			std::vector<double> a = { 5.0, 2.0, 8.0, 3.0, 1.0 }; // Adjust the input values as needed

			// Act
			DWORD IDThread2;
			HANDLE hThread2 = CreateThread(NULL, 0, Thread2Function, &a, CREATE_SUSPENDED, &IDThread2);
			DWORD IDThread3;
			HANDLE hThread3 = CreateThread(NULL, 0, Thread3Function, &a, CREATE_SUSPENDED, &IDThread3);

			// Assuming you have a global HANDLE for Event_1 and Event_2
			SetEvent(Event_1);
			SetEvent(Event_2);

			ResumeThread(hThread2);
			ResumeThread(hThread3);

			WaitForSingleObject(hThread2, INFINITE);
			WaitForSingleObject(hThread3, INFINITE);

			// Assert
			Assert::AreEqual(5.0, a[0]); // Adjust the expected values based on your input
			Assert::AreEqual(8.0, a[1]);
			Assert::AreEqual(2.0, a[2]);
			Assert::AreEqual(3.0, a[3]);
			Assert::AreEqual(1.0, a[4]);

			// Add more assertions based on the expected result after Thread3Function
			Assert::AreEqual(5.0 * 8.0 * 2.0 * 3.0 * 1.0,(double)result);
		}
	};
}