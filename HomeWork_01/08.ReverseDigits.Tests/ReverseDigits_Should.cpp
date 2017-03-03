#include "stdafx.h"
#include "CppUnitTest.h"
#include "../08.ReverseDigits/08.ReverseDigits.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My08ReverseDigitsTests
{		
	TEST_CLASS(ReverseDigits_Should)
	{
	public:
		
		TEST_METHOD(ReverseDigits_WhenValidNumberIsPassed)
		{
			// TODO: Your test code here
			Assert::AreEqual(652, ReverseDigits(256));
		}

	};
}