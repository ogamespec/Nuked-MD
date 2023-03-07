#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}

		/// <summary>
		/// Execute 1 million Z80 cycles and see what it does not crash and how long it takes to execute.
		/// </summary>
		TEST_METHOD(Z80_MegaCycles)
		{
			z80_t state{};
			int clk = state_0;

			size_t cycles = 1000000;

			// One cycle consists of two phases (half cycles)

			while (cycles-- != 0)
			{
				Z80_Clock(&state, clk);
				clk = state_1;

				Z80_Clock(&state, clk);
				clk = state_0;
			}

			// Check duration in Test Explorer :-)
		}
	};
}
