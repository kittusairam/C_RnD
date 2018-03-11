#include "stdafx.h"
#include <stdlib.h>
#include "../src/IdentifyKid.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class IdentifyKidSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes

#pragma endregion 
	
		[TestMethod, Timeout(1000)]
		void IdentifyKid_Invalid()
		{
			char res1 = identifyKid(0, 4);
			Assert::AreEqual('\0', '\0', L"Wrong Answer", 1, 2);
			char res2 = identifyKid(3, 30);
			Assert::AreEqual('\0', '\0', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test1()
		{
			char res = identifyKid(3, 2);
			Assert::AreEqual('B', 'B', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test2()
		{
			char res = identifyKid(3, 4);
			Assert::AreEqual('B', 'B', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test3()
		{
			char res = identifyKid(4, 9);
			Assert::AreEqual('B', 'B', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test4()
		{
			char res = identifyKid(5,5);
			Assert::AreEqual('C', 'C', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test5()
		{
			char res = identifyKid(10, 100);
			Assert::AreEqual('A', 'A', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test6()
		{
			char res = identifyKid(15 ,13564);
			Assert::AreEqual('B', 'B', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test7()
		{
			char res = identifyKid(15, 654978);
			Assert::AreEqual('C', 'C', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test8()
		{
			char res = identifyKid(15, 3216546);
			Assert::AreEqual('B', 'B', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test9()
		{
			char res = identifyKid(15654, 775874);
			Assert::AreEqual('C', 'C', L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void IdentifyKid_Test10()
		{
			char res = identifyKid(15441, 879875);
			Assert::AreEqual('A', 'A', L"Wrong Answer", 1, 2);
		}

	};
}
