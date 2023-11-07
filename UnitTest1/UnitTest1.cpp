#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.3.2/Lab_06_3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 6;
			int array[n] = { 6, 5, 4, 3, 2, 1 };
			int expected_result = 1;
			int result = FindMin(array, n); 
			Assert::AreEqual(expected_result, result);
		}
	};
}
