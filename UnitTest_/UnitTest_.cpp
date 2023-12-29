#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include "../OS 3/OS 3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void SetK(size_t value) {
    k = value;
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
        TEST_METHOD(TestThread2Function)
        {
            std::vector<double> testVector = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            int interval = 0;

            std::stringstream input;
            input << interval << "\n";
            std::cin.rdbuf(input.rdbuf());

            std::stringstream output;
            std::cout.rdbuf(output.rdbuf());

            std::cin.rdbuf(std::cin.rdbuf());
            std::cout.rdbuf(std::cout.rdbuf());

            Assert::AreEqual(1.0, testVector[0]);
            Assert::AreEqual(2.0, testVector[1]);
            Assert::AreEqual(3.0, testVector[2]);
            Assert::AreEqual(4.0, testVector[3]);
            Assert::AreEqual(5.0, testVector[4]);
        }





        TEST_METHOD_INITIALIZE(SetUp) {
            InitializeCriticalSection(&cs);
        }

        TEST_METHOD_CLEANUP(TearDown) {
            DeleteCriticalSection(&cs);
        }

        TEST_METHOD(Thread3Function_CalculatesCorrectly) {

            result = 1;
            std::vector<double> testData = { 2.0, 3.0, 4.0 };
            k = 0;

            DWORD threadId;
            HANDLE hThread = CreateThread(NULL, 0, Thread3Function, &testData, 0, &threadId);
            SetEvent(Event_2);

            WaitForSingleObject(hThread, INFINITE);
            CloseHandle(hThread);

            Assert::AreEqual(2.0 * 3.0 * 4.0, (double) result);
        }

        TEST_METHOD(Thread3Function_SkipsElementsBeforeK) {
            result = 1;

            std::vector<double> testData = { 2.0, 3.0, 4.0 };
            k = 1;

            DWORD threadId;
            HANDLE hThread = CreateThread(NULL, 0, Thread3Function, &testData, 0, &threadId);
            SetEvent(Event_2);

            WaitForSingleObject(hThread, INFINITE);
            CloseHandle(hThread);

            Assert::AreEqual(3.0 * 4.0, (double)result);
        }
	};
}
