#include "pch.h"
#include "CppUnitTest.h"
#include "../oop6.4/oop6_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<int> A(2), B(2);
			int t = A.scalar(A, B);
			Assert::AreEqual(t, 0);
		}
	};
}
