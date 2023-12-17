#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include "../OS 3/OS 3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
	};
}
