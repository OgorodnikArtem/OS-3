#include "pch.h"
#include "CppUnitTest.h"// Include the header file where your functions are declared
#include <vector>
#include "../OS 3/OS 3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Test for the function in Thread2Function
        TEST_METHOD(TestThread2Function)
        {
            std::vector<double> testData;

            int n;

            n = 5;

            double element;
            element = 1.0;

            cout << " ¬ведите элементы : ";
            for (int i = 0; i < n; ++i) {

                testData.push_back(element);

                element += 1.0;

                cout << element;
            }

            Assert::AreEqual(1.0, testData[0]); // Replace with your expected values
            Assert::AreEqual(2.0, testData[1]);
            Assert::AreEqual(3.0, testData[2]);
            Assert::AreEqual(4.0, testData[3]);
            Assert::AreEqual(5.0, testData[4]);
        }
    };
}
